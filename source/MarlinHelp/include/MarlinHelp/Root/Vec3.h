#ifndef LIB_MARLINHELP_ROOT_VEC3
#define LIB_MARLINHELP_ROOT_VEC3 1

// includes from ROOT
#include "TVector3.h"

// Standard library
#include <string>

namespace MarlinHelp {
namespace Root {
namespace Vec3 {
/** Namespace for helper functions that concern ROOT TVector3 (3D vectors).
 **/

std::string print(const TVector3 &vec);

TVector3 rotate_into(const TVector3 &vec, const TVector3 &new_z,
                     const TVector3 &other_plane_axis);

} // namespace Vec3
} // namespace Root
} // namespace MarlinHelp

#endif