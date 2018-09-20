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

TEST(longest_increasing_subsequence_fast, simple3)
{
  constexpr int length = 5;
  int sequence[length];
  std::vector<int> inserter = {
    1, 2, 3, 4, 5,
  };
  std::copy(inserter.begin(), inserter.end(), sequence);
  const int actual = longest_increasing_subsequence_fast(length, sequence);
  EXPECT_EQ(length, actual);
}

TEST(longest_increasing_subsequence_fast, large1)
{
  constexpr int length = 10000;
  std::vector<int> inserter(length);
  std::mt19937 mt(0);
  std::uniform_int_distribution<> dist(0, 10e5);
  for (int i = 0; i < inserter.size(); ++i) {
    inserter[i] = dist(mt);
  }
  std::sort(inserter.begin(), inserter.end());
  int expect = 1;
  for (int i = 1; i < inserter.size(); ++i) {
      if (inserter[i] > inserter[i-1]) {
        expect++;
      }
  }

  int sequence[length];
  std::copy(inserter.begin(), inserter.end(), sequence);
  const int actual = longest_increasing_subsequence_fast(length, sequence);
  EXPECT_EQ(expect, actual);
}
} // namespace dynamic_programming
} // namespace algorithm
