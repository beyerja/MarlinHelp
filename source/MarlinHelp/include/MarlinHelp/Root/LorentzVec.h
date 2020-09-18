#ifndef LIB_MARLINHELP_ROOT_LORENTZVEC
#define LIB_MARLINHELP_ROOT_LORENTZVEC 1

#include "TLorentzVector.h"

namespace MarlinHelp {
namespace Root {
namespace LorentzVec {
/** Namespace for helper functions that concern TLorentzVector.
 **/

std::string print(const TLorentzVector &vec);

TLorentzVector boost_tlv(const TLorentzVector &vec,
                         const TLorentzVector &boost_system);

TLorentzVector rotate_into(const TLorentzVector &vec,
                           const TLorentzVector &new_z,
                           const TLorentzVector &other_plane_axis);

} // namespace LorentzVec
} // namespace Root
} // namespace MarlinHelp

#endif