#include <gtest/gtest.h>

#include <MarlinHelp/Cpp/Num.h>
#include <MarlinHelp/ILD/Machine.h>
#include <MarlinHelp/Root/LorentzVec.h>

// Standard library
#include <cmath>

using namespace MarlinHelp::Cpp;
using namespace MarlinHelp::ILD;
using namespace MarlinHelp::Root;

//------------------------------------------------------------------------------

TEST(TestILD, TestUnboostXAngle) {
  // Test if the crossing angle is correctly boosted away
  double crossing_angle = 0.014;
  double energy = 200;
  double px = energy * sin(crossing_angle / 2.0);
  double m = energy;
  TLorentzVector vec(px, 0, 0, std::sqrt(px * px + m * m));

  // Expected result
  TLorentzVector pred(0, 0, 0, m);

  // Got result
  auto res = Machine::unboost_crossing_angle(vec, energy);

  // Test if results equal within reason
  bool equal = (Num::equal_eps(pred.E(), res.E(), double(1e-4))) &&
               (Num::equal_eps(pred.Px(), res.Px(), double(1e-4))) &&
               (Num::equal_eps(pred.Py(), res.Py(), double(1e-4))) &&
               (Num::equal_eps(pred.Pz(), res.Pz(), double(1e-4)));

  ASSERT_TRUE(equal) << "  Got: " << LorentzVec::print(res)
                     << "\n  Expected: " << LorentzVec::print(pred);
}

//------------------------------------------------------------------------------
