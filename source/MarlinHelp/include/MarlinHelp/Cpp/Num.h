#ifndef LIB_MARLINHELP_CPP_NUM_H
#define LIB_MARLINHELP_CPP_NUM_H 1

namespace MarlinHelp {
namespace Cpp {
namespace Num {
  /** Namespace for numerical helper functions.
   **/
  
  template<class T> bool equal_eps(const T & v1, const T & v2, const T eps=1e-9);
  
} // namespace Num
} // namespace Cpp
} // namespace MarlinHelp

#include <MarlinHelp/Cpp/Num.tpp>

#endif
