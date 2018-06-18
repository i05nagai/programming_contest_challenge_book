#include "chap2/longest_increasing_subsequence/longest_increasing_subsequence.h"
#include <algorithm>
#include <iostream>

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
