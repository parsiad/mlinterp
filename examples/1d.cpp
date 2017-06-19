////////////////////////////////////////////////////////////////////////////////
// 1d.cpp                                                                     //
// ------                                                                     //
//                                                                            //
// Interpolates y = sin(x) on the interval [-pi, pi] using 15 evenly-spaced   //
// data points.                                                               //
////////////////////////////////////////////////////////////////////////////////

#include <mlinterp>

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace mlinterp;
using namespace std;

int main() {

	// End points
	constexpr double b = 3.14159265358979323846, a = -b;

	// Knots (xd) and values at the knots (yd)
	constexpr int nd = 15;
	double xd[nd];
	double yd[nd];
	for(int n = 0; n < nd; ++n) {
		xd[n] = a + (b - a) / (nd - 1) * n;
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
	interp(&nd, ni, yd, yi, xd, xi);

	// Print interpolated values
	cout << scientific << setprecision(8) << showpos;
	for(int n = 0; n < ni; ++n) {
		cout << xi[n] << "\t" << yi[n] << endl;
	}

	return 0;

}

