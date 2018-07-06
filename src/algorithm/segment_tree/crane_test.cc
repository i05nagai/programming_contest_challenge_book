#include "algorithm/segment_tree/crane.h"
#include <gtest/gtest.h>

namespace pccb {
TEST(crane, simple)
{
  const int numCranes = 2;
  const int numCommands = 1;
  int craneLength[] = {
    10, 5
  };
  int points[] = {
    1
  };
  double angles[] = {
    90
  };
  crane(numCranes, numCommands, craneLength, points, angles);
}
} // namespace pccb
