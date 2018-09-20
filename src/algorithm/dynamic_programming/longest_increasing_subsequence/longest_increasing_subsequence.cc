#include "algorithm/dynamic_programming/longest_increasing_subsequence/longest_increasing_subsequence.h"
#include <algorithm>
#include <iostream>

namespace algorithm {
namespace dynamic_programming {
int longest_increasing_subsequence(
    int length,
    int sequence[])
{
  // memo_length[i]:
  // the maximum length of which the sequence ends with sequence[i]
  int memo_length[length];
  // initialize
  std::fill(memo_length, memo_length + length, 1);

  for (size_t i = 1; i < length; ++i) {
    for (size_t j = 0; j < i; ++j) {
      // sequence
      if (sequence[j] <= sequence[i]) {
        memo_length[i] = std::max(memo_length[i], memo_length[j] + 1);
      }
    }
  }

  // find maximum value
  int maximum_length = memo_length[0];
  for (size_t i = 0; i < length; ++i) {
    if (maximum_length < memo_length[i]) {
      maximum_length = memo_length[i];
    }
  }

  return maximum_length;
}

int longest_increasing_subsequence_fast(
    int length,
    int sequence[])
{
  const int INF = 1e9;
  // memo_length[i]:
  // the maximum length of which the sequence ends with sequence[i]
  int dp[length];
  // initialize
  for (size_t i = 0; i < length; ++i) {
    dp[i] = INF;
  }

  for (size_t i = 0; i < length; ++i) {
    *std::lower_bound(dp, dp + length, sequence[i]) = sequence[i];
  }

  return std::lower_bound(dp, dp + length, INF) - dp;
}

int longest_nondeacreasing_subsequence_fast(
    int length,
    int sequence[])
{
  // FIXME
  const int INF = 1e9;
  // memo_length[i]:
  // the maximum length of which the sequence ends with sequence[i]
  int dp[length];
  // initialize
  std::fill(dp, dp + length, INF);

  for (size_t i = 0; i < length; ++i) {
    int l = 0;
    int u = length;
    while (u - l > 1) {
      const int mid = (u + l) / 2;
      if (dp[mid] < sequence[i]) {
        l = mid;
      } else {
        u = mid;
      }
    }
  }

  return std::lower_bound(dp, dp + length, INF) - dp;
}
} // namespace dynamic_programming
} // namespace algorithm
