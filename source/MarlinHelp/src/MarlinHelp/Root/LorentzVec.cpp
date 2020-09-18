#include <MarlinHelp/Root/LorentzVec.h>
#include <MarlinHelp/Root/Vec3.h>

namespace MarlinHelp {
namespace Root {

//------------------------------------------------------------------------------

std::string LorentzVec::print(const TLorentzVector &vec) {
  /** Print the x-y-z content of the vector.
   **/
  return "E: " + std::to_string(vec.E()) + " P: " + std::to_string(vec.Px()) +
         " " + std::to_string(vec.Py()) + " " + std::to_string(vec.Pz());
}

//------------------------------------------------------------------------------

TLorentzVector LorentzVec::boost_tlv(const TLorentzVector &vec,
                                     const TLorentzVector &boost_system) {
  /** Return how the vector (vec) looks in the rest frame of the boost system.
   **/
  auto boosted_vec = vec;
  auto boost_beta_vector = -1.0 * boost_system.BoostVector();
  boosted_vec.Boost(boost_beta_vector);
  return boosted_vec;
}

//------------------------------------------------------------------------------

TLorentzVector LorentzVec::rotate_into(const TLorentzVector &vec,
                                       const TLorentzVector &new_z,
                                       const TLorentzVector &other_plane_axis) {
  /** Rotate vec into the system given by new_z and other_plane_axis.
      For details see the rotation function definiton.
   **/
  auto rotated_mom =
      Vec3::rotate_into(vec.Vect(), new_z.Vect(), other_plane_axis.Vect());
  return TLorentzVector(rotated_mom, vec.E());
}

//------------------------------------------------------------------------------

} // namespace Root
} // namespace MarlinHelp