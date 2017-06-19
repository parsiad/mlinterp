////////////////////////////////////////////////////////////////////////////////
// 2d.cpp                                                                     //
// ------                                                                     //
//                                                                            //
// Interpolates z = sin(x)cos(y) using 15 evenly-spaced points along the x    //
// axis and 15 evenly-spaced points along the y axis.                         //
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

	// Print interpolated values
	cout << scientific << setprecision(8) << showpos;
	for(int n = 0; n < ni; ++n) {
		cout << xi[n] << "\t" << yi[n] << "\t" << zi[n] << endl;
	}

	return 0;

}

