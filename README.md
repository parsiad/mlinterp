# mlinterp
**mlinterp** is a fast C++ routine for multilinear interpolation.

## Installing

First, ensure that you have [CMake](https://cmake.org/) installed on your system. Then, execute the following commands to install the mlinterp library:

```
git clone https://github.com/parsiad/mlinterp.git
cd mlinterp
cmake .
sudo make install
```

If you want to compile the examples, you can also execute:

```
make
```

## Examples

### 1d
Let's interpolate y = sin(x) using 15 evenly-spaced data points on the interval [-pi, pi].

```c++
#include <mlinterp>
using namespace mlinterp;

// Knots (xd) and values at the knots (yd)
constexpr int nd = 15;
double xd[nd];
double yd[nd];
for(int n = 0; n < nd; ++n) {
	xd[n] = -M_PI + (2. * M_PI) / (nd - 1) * n;
	yd[n] = std::sin(xd[n]);
}

// Points at which to interpolate
constexpr int ni = 100;
double xi[ni];
for(int n = 0; n < ni; ++n) {
	xi[n] = -M_PI + (2. * M_PI) / (ni - 1) * n;
}

// Perform interpolation
double yi[ni]; // Result is stored in this buffer
interp(&nd, ni, yd, yi, xd, xi);
```

### 2d

Let's interpolate z = sin(x)cos(y) using 15 evenly-spaced points along the x axis and 30 evenly-spaced points along the y axis.

```c++
#include <mlinterp>
using namespace mlinterp;

// Knots (xd times yd) and values at the knots (zd)
constexpr int nxd = 15, nyd = 15, nd[] = { nxd, nyd };
double xd[nxd];
for(int i = 0; i < nxd; ++i) {
	xd[i] = -M_PI + (2. * M_PI) / (nxd - 1) * i;
}
double yd[nyd];
for(int j = 0; j < nyd; ++j) {
	yd[j] = -M_PI + (2. * M_PI) / (nyd - 1) * j;
}
double zd[nxd * nyd];
for(int i = 0; i < nxd; ++i) {
	for(int j = 0; j < nyd; ++j) {
		const int n = j + i * nyd;
		zd[n] = sin(xd[i]) * cos(yd[j]);
	}
}

// Points at which to interpolate
constexpr int m = 100, ni = m * m;
double xi[ni];
double yi[ni];
for(int i = 0; i < m; ++i) {
	for(int j = 0; j < m; ++j) {
		const int n = j + i * m;
		xi[n] = -M_PI + (2. * M_PI) / (m - 1) * i;
		yi[n] = -M_PI + (2. * M_PI) / (m - 1) * j;
	}
}

// Perform interpolation
double zi[ni]; // Result is stored in this buffer
interp(nd, ni, zd, zi, xd, xi, yd, yi);
```

## Orders

In the 2d example, the interp routine assumes that zd is "ordered" in a certain way.

In particular, if ```i``` is the index associated with the x axis and ```j``` is the index associated with the y axis, ```n = j + i * nyd```  gives the index of the corresponding element in the zd array.

This is referred to as the *natural order*, and it generalizes to arbitrary dimensions. If instead we wanted ```n = i + j * nxd```, we would use the *reverse natural order*, which can be invoked by using

```
interp<rnatord>(nd, ni, zd, zi, xd, xi, yd, yi);
```

in lieu of the call to ```interp``` in the example.

### Custom orders

You are free to define your own ordering scheme. To get a sense of how to do this, it's easiest to study the code for the natural order:

```c++
struct natord {
	template <typename Index, Index Dimension>
	static Index mux(const Index *nd, const Index *indices) {
		Index index = 0, product = 1, i = Dimension - 1;
		while(true) {
			index += indices[i] * product;
			if(i == 0) { break; }
			product *= nd[i--];
		}
		return index;
	}
};
```