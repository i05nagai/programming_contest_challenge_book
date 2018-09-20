#include <gtest/gtest.h>
#include "algorithm/dynamic_programming/traveling_by_stagecoach.h"

namespace algorithm {
namespace dynamic_programming {

TEST(traveling_by_stagecoach, simple1)
{
  const int num_ticket = 2;
  const int num_city = 4;
  const int start_v = 2;
  const int end_v = 1;
  int tickets[] = {
    3, 1,
  };
  std::vector<int> d[num_city];
  for (int i = 0; i < num_city; ++i) {
    d[i].resize(num_city);
    for (int j = 0; j < num_city; ++j) {
      d[i][j] = 0;
    }
  }

  // fill upper right triangular matrix
  d[0][1] = -1;
  d[0][2] = 3;
  d[0][3] = 2;
  d[1][2] = 3;
  d[1][3] = 5;
  d[2][3] = -1;

  // copy to left-lower triangular
  for (int i = 1; i < num_city; ++i) {
    for (int j = 0; j < i; ++j) {
      d[i][j] = d[j][i];
    }
  }

  const double actual = solve_traveling_by_stagecoach(
      d,
      num_ticket,
      num_city,
      start_v,
      end_v,
      tickets);
  EXPECT_NEAR(3.667, actual, 1e-3);
}
} // namespace dynamic_programming
} // namespace algorithm
