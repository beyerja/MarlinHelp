#ifndef LIB_MARLINHELP_ROOT_LORENTZVEC
#define LIB_MARLINHELP_ROOT_LORENTZVEC 1

#include "TLorentzVector.h"

namespace MarlinHelp {
namespace Root {
namespace LorentzVec {
/** Namespace for helper functions that concern TLorentzVector.
 **/
  
TLorentzVector boost_tlv(const TLorentzVector &vec, const TLorentzVector &boost_system );

} // namespace MCHelp
} // namespace Particle
} // namespace MarlinHelp

#endif