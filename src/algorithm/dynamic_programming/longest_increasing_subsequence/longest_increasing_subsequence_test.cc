#include "algorithm/dynamic_programming/longest_increasing_subsequence/longest_increasing_subsequence.h"
#include <gtest/gtest.h>

namespace algorithm {
namespace dynamic_programming {
TEST(longest_increasing_subsequence, simple1)
{
  constexpr int length = 5;
  int sequence[length];
  std::vector<int> inserter = {
    4, 2, 3, 1, 5,
  };
  std::copy(inserter.begin(), inserter.end(), sequence);
  const int actual = longest_increasing_subsequence(length, sequence);
  EXPECT_EQ(3, actual);
}

TEST(longest_increasing_subsequence, simple2)
{
  constexpr int length = 10;
  int sequence[length];
  std::vector<int> inserter = {
    4, 2, 3, 1, 5, 2, 3, 5, 6, 7,
  };
  std::copy(inserter.begin(), inserter.end(), sequence);
  const int actual = longest_increasing_subsequence(length, sequence);
  EXPECT_EQ(6, actual);
}

TEST(longest_increasing_subsequence_fast, simple1)
{
  constexpr int length = 5;
  int sequence[length];
  std::vector<int> inserter = {
    4, 2, 3, 1, 5,
  };
  std::copy(inserter.begin(), inserter.end(), sequence);
  const int actual = longest_increasing_subsequence_fast(length, sequence);
  EXPECT_EQ(3, actual);
}

TEST(longest_increasing_subsequence_fast, simple2)
{
  constexpr int length = 10;
  int sequence[length];
  std::vector<int> inserter = {
    4, 2, 3, 1, 5, 2, 3, 5, 6, 7,
  };
  std::copy(inserter.begin(), inserter.end(), sequence);
  const int actual = longest_increasing_subsequence_fast(length, sequence);
  EXPECT_EQ(6, actual);
}

} // namespace dynamic_programming
} // namespace algorithm
