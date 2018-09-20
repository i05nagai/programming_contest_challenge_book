#include "algorithm/bucket_method/k_th_number.h"
#include <gtest/gtest.h>

namespace algorithm {
TEST(bucket_method, SolveKThNumber)
{
  const int num_seq = 7;
  int seq[] = {
    1,
    5,
    2,
    6,
    3,
    7,
    4,
  };
  // i, j, k
  // i < j
  // (j - i) >= k - 1
  // k-th smallest element in seq[i, j]
  std::vector<std::vector<int>> queries = {
    {2, 5, 3},
    {3, 3, 1},
    {0, 6, 3},
  };
  const std::vector<int> actual = SolveKThNumber(num_seq, seq, queries);
  const std::vector<int> expected = {
    6,
    6,
    3,
  };
  for (int i = 0; i < expected.size(); ++i) {
    EXPECT_EQ(expected[i], actual[i]);
  }
}
} // namespace algorithm
