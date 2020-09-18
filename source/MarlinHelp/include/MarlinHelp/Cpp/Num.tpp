#ifndef LIB_MARLINHELP_CPP_NUM_TPP
#define LIB_MARLINHELP_CPP_NUM_TPP 1

#include <MarlinHelp/Cpp/Num.h>

#include <type_traits> // To check type of template class
#include <cmath>

namespace MarlinHelp {
namespace Cpp {

//------------------------------------------------------------------------------

template<class T> 
bool Num::equal_eps(const T & v1, const T & v2, const T eps) {
  /** Compare two floating point numbers using a maximum distance epsilon.
  **/
  static_assert(std::is_floating_point<T>::value,
    "equal_to_eps can only be called with floating point types");

  return fabs(v1 - v2) < eps;
}

//------------------------------------------------------------------------------

} // namespace Cpp
} // namespace MarlinHelp

#endif