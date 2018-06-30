#include "chap3/binary_search/aggressive_cows.h"
#include <gtest/gtest.h>

namespace pccb {
  TEST(aggressive_cows_test, simple1)
  {
    const int num_stall = 5;
    const int num_cow = 3;
    int dist[] = {
      1,
      2,
      8,
      4,
      9,
    };
    const int actual = solve_aggressive_cows(num_stall, num_cow, dist);
    EXPECT_EQ(3, actual);
  }
} // namespace pccb
