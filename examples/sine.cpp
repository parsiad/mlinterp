#include <mlinterp>

#include <cmath>
#include <cstddef>
#include <iomanip>
#include <iostream>

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

using namespace mlinterp;
using namespace std;

int main() {

	cout << scientific << setprecision(8) << showpos;

	// Data points
	constexpr size_t nd = 10;
	double xd[nd];
	double yd[nd];
	for(int n = 0; n < nd; ++n) {
		xd[n] = -M_PI + (2. * M_PI) / (nd - 1) * n;
		yd[n] = std::sin(xd[n]);
	}

	// Interpolation points
	constexpr size_t ni = 50;
	double xi[ni];
	double yi[ni];
	for(int n = 0; n < ni; ++n) {
		xi[n] = -M_PI + (2. * M_PI) / (ni - 1) * n;
	}
	mlinterp<double>(&nd, ni, yd, yi, xd, xi);

	// Print interpolated values
	for(int n = 0; n < ni; ++n) {
		cout << xi[n] << "\t" << yi[n] << endl;
	}

	return 0;

}

