#include <algorithm>
#include <vector>
#include <gtest/gtest.h>
#include "algorithm/queue/window_minimum.h"

namespace algorithm {
namespace queue {
TEST(SolveWindowMinimum, simple1)
{
  int sequence[] = {
    1, 3, 5, 4, 2,
  };
  const int sequence_size = 5;
  const int window_size = 3;

  const std::vector<int> actual = SolveWindowMinimum(sequence, sequence_size, window_size);

  const std::vector<int> expect = {
    1, 3, 2,
  };
  for (int i = 0; i < expect.size(); ++i) {
    EXPECT_EQ(expect[i], actual[i]);
  }
}
} // namespace queue
} // namespace algorithm

