#include <cstddef>
#include <limits>
#include <tuple>

namespace mlinterp {

	// Private namespace
	namespace _ {

		template <typename T, typename...>
		struct interp {
			void run(const std::size_t *, std::size_t, std::size_t, std::size_t *, T &) {}
		};

		template <typename T, typename T1, typename T2, typename... Args>
		struct interp<T, T1, T2, Args...> : interp<T, Args...> {
			interp(T1 xd, T2 xi, Args... args) : interp<T, Args...>(args...), xd(xd), xi(xi) {}
			const T *xd;
			const T *xi;
			void run(const std::size_t *nd, std::size_t n, std::size_t bitstr, std::size_t *indices, T &factor) {
				const T x = xi[n];

				T weight;
				std::size_t mid;

				if(x <= xd[0]) {
					// Data point is less than left boundary
					mid = 0;
					weight = 1.;
				} else if(x >= xd[*nd - 1]) {
					// Data point is greater than right boundary
					mid = *nd - 2;
					weight = 0.;
				} else {
					// Binary search to find tick
					std::size_t lo = 0, hi = *nd - 2;
					mid = 0;
					weight = 0.;
					while(lo <= hi) {
						mid = lo + (hi - lo) / 2;
						if(x < xd[mid]) { hi = mid - 1; }
						else if(x >= xd[mid + 1]) { lo = mid + 1; }
						else {
							weight = ( xd[mid + 1] - x ) / ( xd[mid + 1] - xd[mid] );
							break;
						}
					}
				}

				if(bitstr & 1) {
					*indices = mid;
					factor *= weight;
				} else {
					*indices = mid + 1;
					factor *= 1 - weight;
				}

				interp<T, Args...> &base = (*this);
				base.run(nd+1, n, bitstr >> 1, indices+1, factor);
			}
		};

	}

	template <std::size_t Dimension>
	struct natord {
		static std::size_t mux(const std::size_t *nd, const std::size_t *indices) {
			std::size_t index = 0, product = 1;
			for(std::size_t i = 0; i < Dimension; ++i) {
				index += indices[i] * product;
				product *= nd[i];
			}
			return index;
		}
	};

	template <typename T, typename... Args, typename Mux = natord<sizeof...(Args)/2>>
	static void mlinterp(const std::size_t *nd, std::size_t ni, const T *yd, T *yi, Args... args) {
		// Infer dimension
		static_assert(sizeof...(Args) % 2 == 0, "needs 4+2*Dimension arguments");
		constexpr std::size_t Dimension = sizeof...(Args)/2;

		// 2^dimension
		constexpr std::size_t Power = 1 << Dimension;

		// Unpack arguments
		_::interp<T, Args...> I(args...);

		// Buffers
		std::size_t indices[Dimension];
		T factor;

		// Perform interpolation for each point in input list
		for(std::size_t n = 0; n < ni; ++n) {
			yi[n] = 0.;
			for(std::size_t bitstr = 0; bitstr < Power; ++bitstr) {
				factor = 1.;
				I.run(nd, n, bitstr, indices, factor);
				if(factor > std::numeric_limits<T>::epsilon()) {
					const std::size_t k = Mux::mux(nd, indices);
					yi[n] += factor * yd[k];
				}
			}
		}
	}

}

