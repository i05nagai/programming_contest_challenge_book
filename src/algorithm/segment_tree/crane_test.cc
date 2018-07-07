#include "algorithm/segment_tree/crane.h"
#include <gtest/gtest.h>

namespace pccb {
TEST(crane_test, simple1)
{
  const int numCranes = 2;
  const int numCommands = 1;
  int craneLength[] = {
    10, 5
  };
  int points[] = {
    1
  };
  int angles[] = {
    90
  };
  const std::vector<std::pair<double, double>> actual
    = SolveCrane(numCranes, numCommands, craneLength, points, angles);
  std::vector<std::pair<double, double>> expect = {
    std::make_pair(5.0, 10.0),
  };
  for (int i = 0; i < expect.size(); i++) {
    EXPECT_DOUBLE_EQ(expect[i].first, actual[i].first);
    EXPECT_DOUBLE_EQ(expect[i].second, actual[i].second);
  }
}

TEST(crane_test, simple2)
{
  const int numCranes = 3;
  const int numCommands = 2;
  int craneLength[] = {
    5, 5, 5,
  };
  int points[] = {
    1, 2,
  };
  int angles[] = {
    270, 90,
  };
  const std::vector<std::pair<double, double>> actual
    = SolveCrane(numCranes, numCommands, craneLength, points, angles);
  std::vector<std::pair<double, double>> expect = {
    std::make_pair(-10.0, 5.0),
    std::make_pair(-5.0, 10.0),
  };
  for (int i = 0; i < expect.size(); i++) {
    EXPECT_DOUBLE_EQ(expect[i].first, actual[i].first);
    EXPECT_DOUBLE_EQ(expect[i].second, actual[i].second);
  }
}
} // namespace pccb
