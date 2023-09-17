# MIT License
#
# Copyright (c) 2023 Parsiad Azimzadeh
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

import os
from ctypes import CDLL, POINTER, c_double, c_float, c_size_t

import numpy as np

lib = CDLL(os.path.join(os.path.dirname(os.path.abspath(__file__)), "libmlinterp.so"))


def interp(yd: np.ndarray, *xs: np.ndarray, row_major: bool = True) -> np.ndarray:
    """Interpolate in arbitrary dimensions.

    Examples
    --------
    In k dimensions with axes x1, x2, ..., xk, the interp routine is called as follows:

    >>> yi = interp(
    ...     yd,                                # Output data
    ...     x1d, x1i, x2d, x2i, ..., xkd, xki  # Input axes
    ... )

    The suffix d refers to data points while the suffix i refers to interpolated values.
    We can think of it as generalizing the numpy function yi = np.interp(x1i, x1d, yd).

    Parameters
    ----------
    yd
        Output data
    xs
        One-dimensional input axes (see above)
    row_major
        Whether to use row or column major ordering

    Returns
    -------
    Interpolated output values
    """
    order = "C" if row_major else "F"

    yd = yd.reshape(-1, order=order)

    dim_times_2 = len(xs)
    if dim_times_2 % 2 == 1:
        msg = "Wrong number of input axis arguments"
        raise ValueError(msg)
    dim = dim_times_2 // 2

    if any(x.ndim != 1 for x in xs):
        msg = "Input axes"
        raise ValueError(msg)

    dtype = yd.dtype
    if any(dtype != x.dtype for x in xs):
        msg = "dtypes do not match"
        raise ValueError(msg)
    if dtype == np.float32:
        c_real_ptr = POINTER(c_float)
    elif dtype == np.float64:
        c_real_ptr = POINTER(c_double)
    else:
        msg = f"Unsupported dtype `{yd.dtype}`"
        raise ValueError(msg)

    yd_ptr = yd.ctypes.data_as(c_real_ptr)
    xs_ptr = [x.ctypes.data_as(c_real_ptr) for x in xs]

    nd = np.array([xs[2 * i].size for i in range(dim)], dtype=np.uint64)
    nd_ptr = nd.ctypes.data_as(POINTER(c_size_t))

    ni = xs[1].size
    nis = [xs[2 * i + 1].size for i in range(dim)]
    if any(ni != ni_ for ni_ in nis):
        msg = f"Number of interpolation points do not match (encountered {', '.join(str(ni_) for ni_ in nis)})"
        raise ValueError(msg)
    ni_value = c_size_t(ni)

    yi = np.zeros_like(xs[1])
    yi_ptr = yi.ctypes.data_as(c_real_ptr)

    try:
        func = getattr(lib, f"interp_{dim}d_{dtype}_{order}")
    except NameError:
        msg = f"Dimension {dim} of type {dtype} and order {order} is not supported"
        raise ValueError(msg)

    func(nd_ptr, ni_value, yd_ptr, yi_ptr, *xs_ptr)

    return yi
