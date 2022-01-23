#include "pccb/chap3/dynamic_programming/color_blocks.h"
#include <gtest/gtest.h>

namespace pccb {
  TEST(SolveColorBlocks, Simple1)
  {
    const int n = 1;
    const double actual = SolveColorBlocks(n);
    EXPECT_EQ(2, actual);
  }

  TEST(SolveColorBlocks, Simple2)
  {
    const int n = 2;
    const double actual = SolveColorBlocks(n);
    EXPECT_EQ(6, actual);
  }
} // namespace pccb

