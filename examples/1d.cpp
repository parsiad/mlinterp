////////////////////////////////////////////////////////////////////////////////
// 1d.cpp                                                                     //
// ------                                                                     //
//                                                                            //
// Interpolates y = sin(x) using 15 evenly-spaced data points on the interval //
// [-pi, pi].                                                                 //
////////////////////////////////////////////////////////////////////////////////

#include <mlinterp>

#include <cmath>
#include <iomanip>
#include <iostream>

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

using namespace mlinterp;
using namespace std;

int main() {

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

	// Print interpolated values
	cout << scientific << setprecision(8) << showpos;
	for(int n = 0; n < ni; ++n) {
		cout << xi[n] << "\t" << yi[n] << endl;
	}

	return 0;

}

