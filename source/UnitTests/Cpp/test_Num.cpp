#include <gtest/gtest.h>

#include <MarlinHelp/Cpp/Num.h>

// Standard library
#include <vector>

using namespace MarlinHelp::Cpp;

//------------------------------------------------------------------------------
// Tests for equal_eps

TEST(TestNum, EqEpsOneEqOne) {
  // Test if one equals one at high precision
  std::vector<double> precisions{1e-1,  1e-2,  1e-3,  1e-5,  1e-7, 1e-9,
                                 1e-11, 1e-13, 1e-15, 1e-18, 1e-20};
  for (auto &precision : precisions) {
    ASSERT_EQ(Num::equal_eps(1.0, 1.0, precision), true)
        << "Failed at precision " << precision;
  }
}

TEST(TestNum, EqEpsNanoPrecision) {
  // Test if 10^-9 precision hold for different orders of magnitude
  srand(unsigned(1.0)); // Set random seed
  std::vector<double> test_numbers{1e-1, 1e-2, 1e-3, 1e-5, 1e-7,
                                   1e1,  1e2,  1e3,  1e5,  1e7};
  // Randomize numbers a bit -> Multiply by factor between 1 and 9
  for (auto &number : test_numbers) {
    number *= 1.0 + (rand() / (RAND_MAX / (9.0 - 1.0)));
  }

  for (auto &number : test_numbers) {
    ASSERT_EQ(Num::equal_eps(number, number, 1e-9), true)
        << "Failed for number " << number;
  }
}

TEST(TestNum, EqEpsUnequalWithOffsets) {
  // Test if numbers still recognized as unequal if large offsets are added
  double n1 = 2e-8;
  double n2 = 3e-8;
  double precision = 1e-9; // Should be sufficient to see difference
  std::vector<double> offsets{1e-1, 1e-2, 1e-3, 1e-5, 1e-7,
                              1e1,  1e2,  1e3,  1e5,  1e7};
  for (auto &offset : offsets) {
    ASSERT_EQ(Num::equal_eps(n1 + offset, n2 + offset, precision), false)
        << "Failed at offset " << offset;
  }
}

TEST(TestNum, EqEpsWorksForAllFloatingTypes) {
  // Test that floating point comparison works for all floating point types
  float f_val = 0.1;
  double d_val = 0.1;
  ASSERT_EQ(Num::equal_eps(f_val, f_val, (float)1e-9), true);
  ASSERT_EQ(Num::equal_eps(d_val, d_val, (double)1e-9), true);
}

//------------------------------------------------------------------------------
