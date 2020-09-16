#include <gtest/gtest.h>

#include <MarlinHelp/Root/LorentzVec.h>

using namespace MarlinHelp::Root;

//------------------------------------------------------------------------------

TEST(TestLorentzVec, zBoost) {
  TLorentzVector vec(1.1, 2.2, 3.5, 25); // Particle moving in positive z
  TLorentzVector boost_vec(0, 0, 3, 5);  // pZ = 3, E = 5, m = 4 (GeV)
  double beta = 3.0 / 5.0;
  double gamma = 5.0 / 4.0;

  // Prediction from relativistic formula
  auto px_pred = vec.Px();
  auto py_pred = vec.Py();
  auto pz_pred = gamma * (vec.Pz() - beta * vec.E());
  auto E_pred = gamma * (vec.E() - beta * vec.Pz());
  auto M_pred = vec.M();

  auto boosted_vec = LorentzVec::boost_tlv(vec, boost_vec);

  auto px_res = boosted_vec.Px();
  auto py_res = boosted_vec.Py();
  auto pz_res = boosted_vec.Pz();
  auto E_res = boosted_vec.E();
  auto M_res = boosted_vec.M();

  ASSERT_EQ(px_res, px_pred);
  ASSERT_EQ(py_res, py_pred);
  ASSERT_EQ(pz_res, pz_pred);
  ASSERT_EQ(E_res, E_pred);
  ASSERT_EQ(M_res, M_pred);
}

//------------------------------------------------------------------------------

TEST(TestLorentzVec, TestRotation) {
  // Test if rotation works (small test, larger in rotation fct test)
  TLorentzVector tlv(1, -1, 1, 20); // Object to rotate

  // Rotation directions
  TLorentzVector new_z_direction(1, 0, 0, 10);
  TLorentzVector other_plane_direction(0, 0, 1, 5);

  // Rotate
  auto res_tlv =
      LorentzVec::rotate_into(tlv, new_z_direction, other_plane_direction);

  // Expected result
  TLorentzVector pred_tlv(1, 1, 1, 20);

  ASSERT_EQ(res_tlv, pred_tlv);
}

//------------------------------------------------------------------------------
