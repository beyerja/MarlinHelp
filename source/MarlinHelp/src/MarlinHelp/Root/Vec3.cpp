#include <MarlinHelp/Root/Vec3.h>

// Includes from ROOT
#include "TRotation.h"

namespace MarlinHelp {
namespace Root {

//------------------------------------------------------------------------------

std::string Vec3::print(const TVector3 &vec) {
  /** Print the x-y-z content of the vector.
   **/
  return std::to_string(vec.X()) + " " + std::to_string(vec.Y()) + " " +
         std::to_string(vec.Z());
}

//------------------------------------------------------------------------------

TVector3 Vec3::rotate_into(const TVector3 &vec, const TVector3 &new_z,
                           const TVector3 &other_plane_axis) {
  /** Rotate the given vector to how it looks in the coordinate system where
   *new_z is the z axis, the new x axis lies in the plane of the new_z and the
   *other given axis, and the sign of the y axis wrt. to the plane is positive.
   **/
  // First make sure new z and x are perpendicular unit vectors
  auto z_unit = new_z.Unit();
  auto other_unit = other_plane_axis.Unit();
  
  // Find only part of unit that is perpendicular to other plane axis
  auto new_y = z_unit.Cross(other_unit);
  auto new_x = new_y.Cross(new_z);
  auto x_unit = new_x.Unit();
   
  // Use new x and z axis directions and rotate vec into that system
  TRotation rotation;
  rotation.SetZAxis(z_unit, x_unit);
  rotation.Invert();
  
  return rotation * vec;
}

//------------------------------------------------------------------------------

} // namespace Root
} // namespace MarlinHelp