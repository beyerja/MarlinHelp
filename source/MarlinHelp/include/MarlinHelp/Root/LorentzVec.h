#ifndef LIB_MARLINHELP_PARTICLE_MC
#define LIB_MARLINHELP_PARTICLE_MC 1

#include "TLorentzVector.h"

namespace MarlinHelp {
namespace Root {
namespace LorentzVec {
/** Namespace for helper functions that concern MCParticles.
 **/
  
TLorentzVector boost_tlv(const TLorentzVector &vec, const TLorentzVector &boost_system );

} // namespace MCHelp
} // namespace Particle
} // namespace MarlinHelp

#endif