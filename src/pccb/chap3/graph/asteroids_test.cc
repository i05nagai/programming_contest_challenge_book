#include "pccb/chap3/graph/asteroids.h"
#include <gtest/gtest.h>

namespace pccb {
  TEST(SolveAsteroids, Simple1)
  {
    const int num_grid = 3;
    const std::vector<Point> asteroids = {
      Point(1, 1),
      Point(1, 3),
      Point(2, 2),
      Point(3, 2),
    };

    const int actual = SolveAsteroids(num_grid, asteroids);
    EXPECT_EQ(2, actual);
  }
} // namespace pccb


