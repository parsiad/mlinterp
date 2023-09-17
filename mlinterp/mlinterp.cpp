#include <cstdarg>
#include <cstddef>

#include "mlinterp.hpp"

using namespace mlinterp;

extern "C" {
void interp_1d_float64_C(size_t *nd, size_t ni, double *yd, double *yi,
                         double *x1d, double *x1i) {
  interp(nd, ni, yd, yi, x1d, x1i);
}

void interp_2d_float64_C(size_t *nd, size_t ni, double *yd, double *yi,
                         double *x1d, double *x1i, double *x2d, double *x2i) {
  interp(nd, ni, yd, yi, x1d, x1i, x2d, x2i);
}

void interp_3d_float64_C(size_t *nd, size_t ni, double *yd, double *yi,
                         double *x1d, double *x1i, double *x2d, double *x2i,
                         double *x3d, double *x3i) {
  interp(nd, ni, yd, yi, x1d, x1i, x2d, x2i, x3d, x3i);
}

void interp_4d_float64_C(size_t *nd, size_t ni, double *yd, double *yi,
                         double *x1d, double *x1i, double *x2d, double *x2i,
                         double *x3d, double *x3i, double *x4d, double *x4i) {
  interp(nd, ni, yd, yi, x1d, x1i, x2d, x2i, x3d, x3i, x4d, x4i);
}

void interp_5d_float64_C(size_t *nd, size_t ni, double *yd, double *yi,
                         double *x1d, double *x1i, double *x2d, double *x2i,
                         double *x3d, double *x3i, double *x4d, double *x4i,
                         double *x5d, double *x5i) {
  interp(nd, ni, yd, yi, x1d, x1i, x2d, x2i, x3d, x3i, x4d, x4i, x5d, x5i);
}

void interp_6d_float64_C(size_t *nd, size_t ni, double *yd, double *yi,
                         double *x1d, double *x1i, double *x2d, double *x2i,
                         double *x3d, double *x3i, double *x4d, double *x4i,
                         double *x5d, double *x5i, double *x6d, double *x6i) {
  interp(nd, ni, yd, yi, x1d, x1i, x2d, x2i, x3d, x3i, x4d, x4i, x5d, x5i, x6d,
         x6i);
}

void interp_7d_float64_C(size_t *nd, size_t ni, double *yd, double *yi,
                         double *x1d, double *x1i, double *x2d, double *x2i,
                         double *x3d, double *x3i, double *x4d, double *x4i,
                         double *x5d, double *x5i, double *x6d, double *x6i,
                         double *x7d, double *x7i) {
  interp(nd, ni, yd, yi, x1d, x1i, x2d, x2i, x3d, x3i, x4d, x4i, x5d, x5i, x6d,
         x6i, x7d, x7i);
}

void interp_8d_float64_C(size_t *nd, size_t ni, double *yd, double *yi,
                         double *x1d, double *x1i, double *x2d, double *x2i,
                         double *x3d, double *x3i, double *x4d, double *x4i,
                         double *x5d, double *x5i, double *x6d, double *x6i,
                         double *x7d, double *x7i, double *x8d, double *x8i) {
  interp(nd, ni, yd, yi, x1d, x1i, x2d, x2i, x3d, x3i, x4d, x4i, x5d, x5i, x6d,
         x6i, x7d, x7i, x8d, x8i);
}

void interp_9d_float64_C(size_t *nd, size_t ni, double *yd, double *yi,
                         double *x1d, double *x1i, double *x2d, double *x2i,
                         double *x3d, double *x3i, double *x4d, double *x4i,
                         double *x5d, double *x5i, double *x6d, double *x6i,
                         double *x7d, double *x7i, double *x8d, double *x8i,
                         double *x9d, double *x9i) {
  interp(nd, ni, yd, yi, x1d, x1i, x2d, x2i, x3d, x3i, x4d, x4i, x5d, x5i, x6d,
         x6i, x7d, x7i, x8d, x8i, x9d, x9i);
}

void interp_10d_float64_C(size_t *nd, size_t ni, double *yd, double *yi,
                          double *x1d, double *x1i, double *x2d, double *x2i,
                          double *x3d, double *x3i, double *x4d, double *x4i,
                          double *x5d, double *x5i, double *x6d, double *x6i,
                          double *x7d, double *x7i, double *x8d, double *x8i,
                          double *x9d, double *x9i, double *x10d,
                          double *x10i) {
  interp(nd, ni, yd, yi, x1d, x1i, x2d, x2i, x3d, x3i, x4d, x4i, x5d, x5i, x6d,
         x6i, x7d, x7i, x8d, x8i, x9d, x9i, x10d, x10i);
}

void interp_1d_float32_C(size_t *nd, size_t ni, float *yd, float *yi,
                         float *x1d, float *x1i) {
  interp(nd, ni, yd, yi, x1d, x1i);
}

void interp_2d_float32_C(size_t *nd, size_t ni, float *yd, float *yi,
                         float *x1d, float *x1i, float *x2d, float *x2i) {
  interp(nd, ni, yd, yi, x1d, x1i, x2d, x2i);
}

void interp_3d_float32_C(size_t *nd, size_t ni, float *yd, float *yi,
                         float *x1d, float *x1i, float *x2d, float *x2i,
                         float *x3d, float *x3i) {
  interp(nd, ni, yd, yi, x1d, x1i, x2d, x2i, x3d, x3i);
}

void interp_4d_float32_C(size_t *nd, size_t ni, float *yd, float *yi,
                         float *x1d, float *x1i, float *x2d, float *x2i,
                         float *x3d, float *x3i, float *x4d, float *x4i) {
  interp(nd, ni, yd, yi, x1d, x1i, x2d, x2i, x3d, x3i, x4d, x4i);
}

void interp_5d_float32_C(size_t *nd, size_t ni, float *yd, float *yi,
                         float *x1d, float *x1i, float *x2d, float *x2i,
                         float *x3d, float *x3i, float *x4d, float *x4i,
                         float *x5d, float *x5i) {
  interp(nd, ni, yd, yi, x1d, x1i, x2d, x2i, x3d, x3i, x4d, x4i, x5d, x5i);
}

void interp_6d_float32_C(size_t *nd, size_t ni, float *yd, float *yi,
                         float *x1d, float *x1i, float *x2d, float *x2i,
                         float *x3d, float *x3i, float *x4d, float *x4i,
                         float *x5d, float *x5i, float *x6d, float *x6i) {
  interp(nd, ni, yd, yi, x1d, x1i, x2d, x2i, x3d, x3i, x4d, x4i, x5d, x5i, x6d,
         x6i);
}

void interp_7d_float32_C(size_t *nd, size_t ni, float *yd, float *yi,
                         float *x1d, float *x1i, float *x2d, float *x2i,
                         float *x3d, float *x3i, float *x4d, float *x4i,
                         float *x5d, float *x5i, float *x6d, float *x6i,
                         float *x7d, float *x7i) {
  interp(nd, ni, yd, yi, x1d, x1i, x2d, x2i, x3d, x3i, x4d, x4i, x5d, x5i, x6d,
         x6i, x7d, x7i);
}

void interp_8d_float32_C(size_t *nd, size_t ni, float *yd, float *yi,
                         float *x1d, float *x1i, float *x2d, float *x2i,
                         float *x3d, float *x3i, float *x4d, float *x4i,
                         float *x5d, float *x5i, float *x6d, float *x6i,
                         float *x7d, float *x7i, float *x8d, float *x8i) {
  interp(nd, ni, yd, yi, x1d, x1i, x2d, x2i, x3d, x3i, x4d, x4i, x5d, x5i, x6d,
         x6i, x7d, x7i, x8d, x8i);
}

void interp_9d_float32_C(size_t *nd, size_t ni, float *yd, float *yi,
                         float *x1d, float *x1i, float *x2d, float *x2i,
                         float *x3d, float *x3i, float *x4d, float *x4i,
                         float *x5d, float *x5i, float *x6d, float *x6i,
                         float *x7d, float *x7i, float *x8d, float *x8i,
                         float *x9d, float *x9i) {
  interp(nd, ni, yd, yi, x1d, x1i, x2d, x2i, x3d, x3i, x4d, x4i, x5d, x5i, x6d,
         x6i, x7d, x7i, x8d, x8i, x9d, x9i);
}

void interp_10d_float32_C(size_t *nd, size_t ni, float *yd, float *yi,
                          float *x1d, float *x1i, float *x2d, float *x2i,
                          float *x3d, float *x3i, float *x4d, float *x4i,
                          float *x5d, float *x5i, float *x6d, float *x6i,
                          float *x7d, float *x7i, float *x8d, float *x8i,
                          float *x9d, float *x9i, float *x10d, float *x10i) {
  interp(nd, ni, yd, yi, x1d, x1i, x2d, x2i, x3d, x3i, x4d, x4i, x5d, x5i, x6d,
         x6i, x7d, x7i, x8d, x8i, x9d, x9i, x10d, x10i);
}

void interp_1d_float64_F(size_t *nd, size_t ni, double *yd, double *yi,
                         double *x1d, double *x1i) {
  interp<rnatord>(nd, ni, yd, yi, x1d, x1i);
}

void interp_2d_float64_F(size_t *nd, size_t ni, double *yd, double *yi,
                         double *x1d, double *x1i, double *x2d, double *x2i) {
  interp<rnatord>(nd, ni, yd, yi, x1d, x1i, x2d, x2i);
}

void interp_3d_float64_F(size_t *nd, size_t ni, double *yd, double *yi,
                         double *x1d, double *x1i, double *x2d, double *x2i,
                         double *x3d, double *x3i) {
  interp<rnatord>(nd, ni, yd, yi, x1d, x1i, x2d, x2i, x3d, x3i);
}

void interp_4d_float64_F(size_t *nd, size_t ni, double *yd, double *yi,
                         double *x1d, double *x1i, double *x2d, double *x2i,
                         double *x3d, double *x3i, double *x4d, double *x4i) {
  interp<rnatord>(nd, ni, yd, yi, x1d, x1i, x2d, x2i, x3d, x3i, x4d, x4i);
}

void interp_5d_float64_F(size_t *nd, size_t ni, double *yd, double *yi,
                         double *x1d, double *x1i, double *x2d, double *x2i,
                         double *x3d, double *x3i, double *x4d, double *x4i,
                         double *x5d, double *x5i) {
  interp<rnatord>(nd, ni, yd, yi, x1d, x1i, x2d, x2i, x3d, x3i, x4d, x4i, x5d,
                  x5i);
}

void interp_6d_float64_F(size_t *nd, size_t ni, double *yd, double *yi,
                         double *x1d, double *x1i, double *x2d, double *x2i,
                         double *x3d, double *x3i, double *x4d, double *x4i,
                         double *x5d, double *x5i, double *x6d, double *x6i) {
  interp<rnatord>(nd, ni, yd, yi, x1d, x1i, x2d, x2i, x3d, x3i, x4d, x4i, x5d,
                  x5i, x6d, x6i);
}

void interp_7d_float64_F(size_t *nd, size_t ni, double *yd, double *yi,
                         double *x1d, double *x1i, double *x2d, double *x2i,
                         double *x3d, double *x3i, double *x4d, double *x4i,
                         double *x5d, double *x5i, double *x6d, double *x6i,
                         double *x7d, double *x7i) {
  interp<rnatord>(nd, ni, yd, yi, x1d, x1i, x2d, x2i, x3d, x3i, x4d, x4i, x5d,
                  x5i, x6d, x6i, x7d, x7i);
}

void interp_8d_float64_F(size_t *nd, size_t ni, double *yd, double *yi,
                         double *x1d, double *x1i, double *x2d, double *x2i,
                         double *x3d, double *x3i, double *x4d, double *x4i,
                         double *x5d, double *x5i, double *x6d, double *x6i,
                         double *x7d, double *x7i, double *x8d, double *x8i) {
  interp<rnatord>(nd, ni, yd, yi, x1d, x1i, x2d, x2i, x3d, x3i, x4d, x4i, x5d,
                  x5i, x6d, x6i, x7d, x7i, x8d, x8i);
}

void interp_9d_float64_F(size_t *nd, size_t ni, double *yd, double *yi,
                         double *x1d, double *x1i, double *x2d, double *x2i,
                         double *x3d, double *x3i, double *x4d, double *x4i,
                         double *x5d, double *x5i, double *x6d, double *x6i,
                         double *x7d, double *x7i, double *x8d, double *x8i,
                         double *x9d, double *x9i) {
  interp<rnatord>(nd, ni, yd, yi, x1d, x1i, x2d, x2i, x3d, x3i, x4d, x4i, x5d,
                  x5i, x6d, x6i, x7d, x7i, x8d, x8i, x9d, x9i);
}

void interp_10d_float64_F(size_t *nd, size_t ni, double *yd, double *yi,
                          double *x1d, double *x1i, double *x2d, double *x2i,
                          double *x3d, double *x3i, double *x4d, double *x4i,
                          double *x5d, double *x5i, double *x6d, double *x6i,
                          double *x7d, double *x7i, double *x8d, double *x8i,
                          double *x9d, double *x9i, double *x10d,
                          double *x10i) {
  interp<rnatord>(nd, ni, yd, yi, x1d, x1i, x2d, x2i, x3d, x3i, x4d, x4i, x5d,
                  x5i, x6d, x6i, x7d, x7i, x8d, x8i, x9d, x9i, x10d, x10i);
}

void interp_1d_float32_F(size_t *nd, size_t ni, float *yd, float *yi,
                         float *x1d, float *x1i) {
  interp<rnatord>(nd, ni, yd, yi, x1d, x1i);
}

void interp_2d_float32_F(size_t *nd, size_t ni, float *yd, float *yi,
                         float *x1d, float *x1i, float *x2d, float *x2i) {
  interp<rnatord>(nd, ni, yd, yi, x1d, x1i, x2d, x2i);
}

void interp_3d_float32_F(size_t *nd, size_t ni, float *yd, float *yi,
                         float *x1d, float *x1i, float *x2d, float *x2i,
                         float *x3d, float *x3i) {
  interp<rnatord>(nd, ni, yd, yi, x1d, x1i, x2d, x2i, x3d, x3i);
}

void interp_4d_float32_F(size_t *nd, size_t ni, float *yd, float *yi,
                         float *x1d, float *x1i, float *x2d, float *x2i,
                         float *x3d, float *x3i, float *x4d, float *x4i) {
  interp<rnatord>(nd, ni, yd, yi, x1d, x1i, x2d, x2i, x3d, x3i, x4d, x4i);
}

void interp_5d_float32_F(size_t *nd, size_t ni, float *yd, float *yi,
                         float *x1d, float *x1i, float *x2d, float *x2i,
                         float *x3d, float *x3i, float *x4d, float *x4i,
                         float *x5d, float *x5i) {
  interp<rnatord>(nd, ni, yd, yi, x1d, x1i, x2d, x2i, x3d, x3i, x4d, x4i, x5d,
                  x5i);
}

void interp_6d_float32_F(size_t *nd, size_t ni, float *yd, float *yi,
                         float *x1d, float *x1i, float *x2d, float *x2i,
                         float *x3d, float *x3i, float *x4d, float *x4i,
                         float *x5d, float *x5i, float *x6d, float *x6i) {
  interp<rnatord>(nd, ni, yd, yi, x1d, x1i, x2d, x2i, x3d, x3i, x4d, x4i, x5d,
                  x5i, x6d, x6i);
}

void interp_7d_float32_F(size_t *nd, size_t ni, float *yd, float *yi,
                         float *x1d, float *x1i, float *x2d, float *x2i,
                         float *x3d, float *x3i, float *x4d, float *x4i,
                         float *x5d, float *x5i, float *x6d, float *x6i,
                         float *x7d, float *x7i) {
  interp<rnatord>(nd, ni, yd, yi, x1d, x1i, x2d, x2i, x3d, x3i, x4d, x4i, x5d,
                  x5i, x6d, x6i, x7d, x7i);
}

void interp_8d_float32_F(size_t *nd, size_t ni, float *yd, float *yi,
                         float *x1d, float *x1i, float *x2d, float *x2i,
                         float *x3d, float *x3i, float *x4d, float *x4i,
                         float *x5d, float *x5i, float *x6d, float *x6i,
                         float *x7d, float *x7i, float *x8d, float *x8i) {
  interp<rnatord>(nd, ni, yd, yi, x1d, x1i, x2d, x2i, x3d, x3i, x4d, x4i, x5d,
                  x5i, x6d, x6i, x7d, x7i, x8d, x8i);
}

void interp_9d_float32_F(size_t *nd, size_t ni, float *yd, float *yi,
                         float *x1d, float *x1i, float *x2d, float *x2i,
                         float *x3d, float *x3i, float *x4d, float *x4i,
                         float *x5d, float *x5i, float *x6d, float *x6i,
                         float *x7d, float *x7i, float *x8d, float *x8i,
                         float *x9d, float *x9i) {
  interp<rnatord>(nd, ni, yd, yi, x1d, x1i, x2d, x2i, x3d, x3i, x4d, x4i, x5d,
                  x5i, x6d, x6i, x7d, x7i, x8d, x8i, x9d, x9i);
}

void interp_10d_float32_F(size_t *nd, size_t ni, float *yd, float *yi,
                          float *x1d, float *x1i, float *x2d, float *x2i,
                          float *x3d, float *x3i, float *x4d, float *x4i,
                          float *x5d, float *x5i, float *x6d, float *x6i,
                          float *x7d, float *x7i, float *x8d, float *x8i,
                          float *x9d, float *x9i, float *x10d, float *x10i) {
  interp<rnatord>(nd, ni, yd, yi, x1d, x1i, x2d, x2i, x3d, x3i, x4d, x4i, x5d,
                  x5i, x6d, x6i, x7d, x7i, x8d, x8i, x9d, x9i, x10d, x10i);
}
}
