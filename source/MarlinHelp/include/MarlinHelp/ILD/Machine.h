#ifndef LIB_MARLINHELP_ILD_MACHINE_H
#define LIB_MARLINHELP_ILD_MACHINE_H 1

// Includes from ROOT
#include <TLorentzVector.h>

namespace MarlinHelp {
namespace ILD {
namespace Machine {
/** Namespace for helper function for ILD/ILC machine conventions.
 **/
  
TLorentzVector unboost_crossing_angle(const TLorentzVector & vec, double energy);
    
} // namespace Machine
} // namespace ILD
} // namespace MarlinHelp

#endif