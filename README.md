# mlinterp
**mlinterp** is a fast C++ routine for linear interpolation in arbitrary dimensions (i.e., multilinear interpolation).

mlinterp is written by [Parsiad Azimzadeh](http://parsiad.ca) and released under a permissive MIT License. The latest release can be [downloaded here](https://github.com/parsiad/mlinterp/releases/latest).

## Installing

### Quick and dirty

mlinterp is a header-only library, meaning that the fastest way to use it is to copy the file ```mlinterp/mlinterp.hpp``` into your own project directory and include it using ```#include <mlinterp.hpp>```.

### Clean install

If you are on a UNIX-like system with CMake installed, you can download mlinterp and run the following commands (from the mlinterp project directory) to install it to your system:

```
cmake .
sudo make install # Run this to install
make # Run this to compile examples
```

## Examples

### 1d
Let's interpolate y = sin(x) on the interval [-pi, pi] using 15 evenly-spaced data points.

```c++
using namespace mlinterp;

// End points
constexpr double b = 3.14159265358979323846, a = -b;

// Knots (xd) and values at the knots (yd)
constexpr int nxd = 15, nd[] = { nxd };
double xd[nxd];
double yd[nxd];
for(int n = 0; n < nxd; ++n) {
	xd[n] = a + (b - a) / (nxd - 1) * n;
	yd[n] = sin(xd[n]);
}

// Points at which to interpolate
constexpr int ni = 100;
double xi[ni];
for(int n = 0; n < ni; ++n) {
	xi[n] = a + (b - a) / (ni - 1) * n;
}

// Perform interpolation
double yi[ni]; // Result is stored in this buffer
interp(nd, ni, yd, yi, xd, xi);
```

![](https://raw.githubusercontent.com/parsiad/mlinterp/master/examples/1d.png)

### 2d

Let's interpolate z = sin(x)cos(y) on the interval [-pi, pi] X [-pi, pi] using 15 evenly-spaced points along the x axis and 15 evenly-spaced points along the y axis.

```c++
using namespace mlinterp;

// End points
constexpr double b = 3.14159265358979323846, a = -b;

// Knots (xd times yd) and values at the knots (zd)
constexpr int nxd = 15, nyd = 15, nd[] = { nxd, nyd };
double xd[nxd];
for(int i = 0; i < nxd; ++i) {
	xd[i] = a + (b - a) / (nxd - 1) * i;
}
double yd[nyd];
for(int j = 0; j < nyd; ++j) {
	yd[j] = a + (b - a) / (nyd - 1) * j;
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
		xi[n] = a + (b - a) / (m - 1) * i;
		yi[n] = a + (b - a) / (m - 1) * j;
	}
}

// Perform interpolation
double zi[ni]; // Result is stored in this buffer
interp(nd, ni, zd, zi, xd, xi, yd, yi);
```

![](https://raw.githubusercontent.com/parsiad/mlinterp/master/examples/2d.png)

## Orders

In the 2d example, the interp routine assumes that the array ```zd``` is "ordered" in a certain way.

In particular, if ```i``` is the index associated with the x axis and ```j``` is the index associated with the y axis, ```n = j + i * nyd```  gives the index of the corresponding element in the ```zd``` array.

This is referred to as the *natural order*, and it generalizes to arbitrary dimensions. If instead we wanted ```n = i + j * nxd```, we would use the *reverse natural order*, which can be invoked by using instead

```c++
interp<rnatord>(nd, ni, zd, zi, xd, xi, yd, yi);
```

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
