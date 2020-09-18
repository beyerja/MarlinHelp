#include <MarlinHelp/ILD/Machine.h>
#include <MarlinHelp/Root/LorentzVec.h>

namespace MarlinHelp {
namespace ILD {

//------------------------------------------------------------------------------

TLorentzVector Machine::unboost_crossing_angle(const TLorentzVector &vec,
                                               double energy) {
  /** Boost out of the lab/detector frame and into the system of the two
   *colliding beams. Removes the crossing angle of the beams.
   **/
  double crossing_angle = 0.014;
  TLorentzVector collision_system(energy * sin(crossing_angle / 2.0), 0, 0,
                                  energy);
  
  return Root::LorentzVec::boost_tlv(vec, collision_system);
}

//------------------------------------------------------------------------------

} // namespace ILD
} // namespace MarlinHelp
