#include <MarlinHelp/Root/LorentzVec.h>

namespace MarlinHelp {
namespace Root {
    
//------------------------------------------------------------------------------

TLorentzVector LorentzVec::boost_tlv(const TLorentzVector &vec, const TLorentzVector &boost_system ) {
  /** Return how the vector (vec) looks in the rest frame of the boost system.
   **/
  auto boosted_vec = vec;
  auto boost_beta_vector = -1.0*boost_system.BoostVector();
  boosted_vec.Boost(boost_beta_vector);
  return boosted_vec;
}

//------------------------------------------------------------------------------

} // namespace Root
} // namespace MarlinHelp