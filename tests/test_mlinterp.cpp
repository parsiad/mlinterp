#include <cmath>
#include <gtest/gtest.h>
#include <mlinterp>

using namespace mlinterp;

TEST(test_mlinterp, test_1d) {
  constexpr double b = 3.14159265358979323846, a = -b;

  constexpr int nxd = 100, nd[] = {nxd};
  double xd[nxd];
  double yd[nxd];
  for (int n = 0; n < nxd; ++n) {
    xd[n] = a + (b - a) / (nxd - 1) * n;
    yd[n] = sin(xd[n]);
  }

  constexpr int ni = 1000;
  double xi[ni];
  for (int n = 0; n < ni; ++n) {
    xi[n] = a + (b - a) / (ni - 1) * n;
  }

  double yi[ni];
  interp(nd, ni, yd, yi, xd, xi);

  for (int n = 0; n < ni; ++n) {
    EXPECT_NEAR(yi[n], sin(xi[n]), 0.001);
  }
}

TEST(test_mlinterp, test_2d) {
  constexpr double b = 3.14159265358979323846, a = -b;

  constexpr int nxd = 200, nyd = 150, nd[] = {nxd, nyd};
  double xd[nxd];
  for (int i = 0; i < nxd; ++i) {
    xd[i] = a + (b - a) / (nxd - 1) * i;
  }
  double yd[nyd];
  for (int j = 0; j < nyd; ++j) {
    yd[j] = a + (b - a) / (nyd - 1) * j;
  }
  double *zd = new double[nxd * nyd];
  for (int i = 0; i < nxd; ++i) {
    for (int j = 0; j < nyd; ++j) {
      const int n = j + i * nyd;
      zd[n] = sin(xd[i]) * cos(yd[j]);
    }
  }

  constexpr int m = 1000, ni = m * m;
  double *xi = new double[ni];
  double *yi = new double[ni];
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      const int n = j + i * m;
      xi[n] = a + (b - a) / (m - 1) * i;
      yi[n] = a + (b - a) / (m - 1) * j;
    }
  }

  double *zi = new double[ni];
  interp(nd, ni, zd, zi, xd, xi, yd, yi);

  for (int n = 0; n < ni; ++n) {
    EXPECT_NEAR(zi[n], sin(xi[n]) * cos(yi[n]), 0.001);
  }

  delete[] zd;
  delete[] xi;
  delete[] yi;
  delete[] zi;
}
