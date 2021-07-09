#include <gtest/gtest.h>

#include <MarlinHelp/Cpp/Num.h>
#include <MarlinHelp/Whizard/WeightFileReader.h>

// Standard library
#include <string>

using namespace MarlinHelp::Cpp;
using namespace MarlinHelp::Whizard;

const std::string test_path{
    "../source/UnitTests/Whizard/TestWeightFile.weights.dat"};

TEST(TestWeightFileReader, DefaultConstructor) {
  WeightFileReader wfr{};
  ASSERT_EQ(wfr.n_events(), 0) << "Found " << wfr.n_events();
}
  
TEST(TestWeightFileReader, TestFileReading) {
  WeightFileReader wfr(test_path);

  ASSERT_EQ(wfr.n_events(), 8) << "Found " << wfr.n_events();
  ASSERT_EQ(wfr.n_points(), 18) << "Found " << wfr.n_points();

  // Test a few points
  ASSERT_TRUE(Num::equal_eps(wfr[0][0], 9.9957310465E-01))
      << "Expected " << 9.9957310465E-01 << " got " << wfr[0][0];
  ASSERT_TRUE(Num::equal_eps(wfr[7][17], 1.0001422973E+00))
      << "Expected " << 1.0001422973E+00 << " got " << wfr[7][17];
  ASSERT_TRUE(Num::equal_eps(wfr[5][13], 9.9780584531E-01))
      << "Expected " << 9.9780584531E-01 << " got " << wfr[7][17];
}