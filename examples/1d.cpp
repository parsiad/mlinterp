////////////////////////////////////////////////////////////////////////////////
// 1d.cpp                                                                     //
// ------                                                                     //
//                                                                            //
// Interpolates y = sin(x) on the interval [-pi, pi] using 15 evenly-spaced   //
// points.                                                                    //
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

	// Subdivide the interval [-pi, pi] using 15 evenly-spaced points and
	// evaluate sin(x) at each of those points
	constexpr int nxd = 15, nd[] = { nxd };
	double xd[nxd];
	double yd[nxd];
	for(int n = 0; n < nxd; ++n) {
		xd[n] = a + (b - a) / (nxd - 1) * n;
		yd[n] = sin(xd[n]);
	}

	// Subdivide the interval [-pi, pi] using 100 evenly-spaced points
	// (these are the points at which we interpolate)
	constexpr int ni = 100;
	double xi[ni];
	for(int n = 0; n < ni; ++n) {
		xi[n] = a + (b - a) / (ni - 1) * n;
	}

	// Perform the interpolation
	double yi[ni]; // Result is stored in this buffer
	interp(
		nd, ni, // Number of points
		yd, yi, // Output axis (y)
		xd, xi  // Input axis (x)
	);

	// Print the interpolated values
	cout << scientific << setprecision(8) << showpos;
	for(int n = 0; n < ni; ++n) {
		cout << xi[n] << "\t" << yi[n] << endl;
	}

	return 0;

}

