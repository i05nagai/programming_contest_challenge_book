#include "cp/chap01/solve_matching.h"
#include <gtest/gtest.h>

namespace cp {
  TEST(solve_matching_test, simple1)
  {
    const int num = 2;
    int x[] = {
      1, 8, 6, 1,
    };
    int y[] = {
      1, 6, 8, 3,
    };
    const double actual = solve_matching(num, x, y);
    EXPECT_NEAR(4.83, actual, 1e-2);
  }
} // namespace cp
