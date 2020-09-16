#include <gtest/gtest.h>

#include <MarlinHelp/Root/Vec3.h>

using namespace MarlinHelp::Root;

//------------------------------------------------------------------------------

TEST(TestVec3, TestPrint) {
  // Test if vector printing works correctly
  TVector3 v(1, -1, 0.5);

  ASSERT_STREQ(Vec3::print(v).c_str(), "1.000000 -1.000000 0.500000");
}

//------------------------------------------------------------------------------

TEST(TestVec3, TestRotationZ) {
  // Test if rotation by simple moving of Z works
  TVector3 v1(1, 0, 0);
  TVector3 v2(0, 1, 0);
  TVector3 v3(0, 0, 1);

  struct RotRes {
    // Set of rotation and expected result
    std::string name;
    TVector3 new_z;
    TVector3 other_axis;
    TVector3 pred_v1_rot;
    TVector3 pred_v2_rot;
    TVector3 pred_v3_rot;
  };

  std::vector<RotRes> tests{
      RotRes{"trivial",         //
             TVector3(0, 0, 1), // Rotate so that new z is y axis
             TVector3(1, 0, 0), // Keep x where it is (in the xz plane)
             v1, v2, v3},
      RotRes{
          "Z rotation",      //
          TVector3(0, 1, 0), // Rotate so that new z is y axis
          TVector3(1, 0, 0), // Keep x where it is (in the xz plane)
          v1,                // Results expected by drawing this on paper
          TVector3(0, 0, 1), //
          TVector3(0, -1, 0) //
      },
      RotRes{
          "X rotation",         //
          TVector3(0, 0, 1),    // Keep z axis
          TVector3(0, 2, -0.5), // new x axis in x-y plane (expect in on y axis)
          TVector3(0, -1, 0),   // Results expected by drawing this on paper
          TVector3(1, 0, 0),    //
          v3                    //
      },
      RotRes{
          "Switch",           // x' is former z, z' is former x
          TVector3(1, 0, 0), // New z axis
          TVector3(0, 0, 1),  //
          TVector3(0, 0, 1),  //
          TVector3(0, -1, 0), //
          TVector3(1, 0, 0)   //
      }};

  for (const auto &test : tests) {
    auto res_v1_rot = Vec3::rotate_into(v1, test.new_z, test.other_axis);
    auto res_v2_rot = Vec3::rotate_into(v2, test.new_z, test.other_axis);
    auto res_v3_rot = Vec3::rotate_into(v3, test.new_z, test.other_axis);

    EXPECT_EQ(res_v1_rot, test.pred_v1_rot)
        << test.name << " Pred: " << Vec3::print(test.pred_v1_rot)
        << " Res: " << Vec3::print(res_v1_rot);
    EXPECT_EQ(res_v2_rot, test.pred_v2_rot)
        << test.name << " Pred: " << Vec3::print(test.pred_v2_rot)
        << " Res: " << Vec3::print(res_v2_rot);
    EXPECT_EQ(res_v3_rot, test.pred_v3_rot)
        << test.name << " Pred: " << Vec3::print(test.pred_v3_rot)
        << " Res: " << Vec3::print(res_v3_rot);
  }
}

//------------------------------------------------------------------------------