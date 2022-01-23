#include "pccb/chap3/dynamic_programming/domino.h"
#include <gtest/gtest.h>

namespace pccb {
  TEST(SolveDomino, Simple1)
  {
    const int n = 3;
    const int m = 3;
    bool color[MAX_N][MAX_N] = {
      {false, false, false},
      {false, true, false},
      {false, false, false},
    };
    const double actual = SolveDomino(n, m, color, 10);
    EXPECT_EQ(2, actual);
  }
} // namespace pccb
