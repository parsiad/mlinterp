////////////////////////////////////////////////////////////////////////////////
// 2d.cpp                                                                     //
// ------                                                                     //
//                                                                            //
// Interpolates z = sin(x)cos(y) on the interval [-pi, pi] X [-pi, pi] using  //
// 15 evenly-spaced points along the x axis and 15 evenly-spaced points along //
// the y axis.                                                                //
////////////////////////////////////////////////////////////////////////////////

#include <mlinterp>

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace mlinterp;
using namespace std;

int main() {

	// Boundaries of the interval [-pi, pi]
	constexpr double b = 3.14159265358979323846, a = -b;

	// Discretize the set [-pi, pi] X [-pi, pi] using 15 evenly-spaced
	// points along the x axis and 15 evenly-spaced points along the y axis
	// and evaluate sin(x)cos(y) at each of those points
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

	// Subdivide the set [-pi, pi] X [-pi, pi] using 100 evenly-spaced
	// points along the x axis and 100 evenly-spaced points along the y axis
	// (these are the points at which we interpolate)
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

	// Perform the interpolation
	double zi[ni]; // Result is stored in this buffer
	interp(
		nd, ni,        // Number of points
		zd, zi,        // Output axis (z)
		xd, xi, yd, yi // Input axes (x and y)
	);

	// Print the interpolated values
	cout << scientific << setprecision(8) << showpos;
	for(int n = 0; n < ni; ++n) {
		cout << xi[n] << "\t" << yi[n] << "\t" << zi[n] << endl;
	}

	return 0;

}

