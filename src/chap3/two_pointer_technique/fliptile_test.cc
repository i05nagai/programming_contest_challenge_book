#include "chap3/two_pointer_technique/fliptile.h"
#include <gtest/gtest.h>

namespace pccb {
  TEST(fliptile_test, simple1)
  {
    const int row = 4;
    const int col = 4;
    const std::vector<std::vector<int>> tiles = {
      {1, 0, 0, 1,},
      {0, 1, 1, 0,},
      {0, 1, 1, 0,},
      {1, 0, 0, 1,},
    };
    const std::pair<std::vector<std::vector<int>>, int> actual
      = solve_fliptile(row, col, tiles);
    std::vector<std::vector<int>> expect = {
      {0, 0, 0, 0,},
      {1, 0, 0, 1,},
      {1, 0, 0, 1,},
      {0, 0, 0, 0,},
    };
    for (int r = 0; r < row; ++r) {
      for (int c = 0; c < col; ++c) {
        EXPECT_EQ(expect[r][c], actual.first[r][c]);
      }
    }
  }
} // namespace pccb

