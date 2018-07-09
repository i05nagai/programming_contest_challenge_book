#include "pccb/chap3/two_pointer_technique/subsequence.h"
#include <algorithm>
#include <cassert>

namespace pccb {
  int solve_subsequence_simple(
      const int length,
      const int total,
      int sequence[]) {
    // assert(length > 10);
    assert(10e9 > total);
    constexpr int INF = 1e8;

    // sums[0]: 0
    // sums[i+1]: summation of sequence from 0 to i
    // sum[j] - sum[i]: summation of seuqnece form i to j - 1
    int sums[length + 1];
    sums[0] = 0;
    for (int i = 0; i < length; ++i) {
      sums[i + 1] = sequence[i] + sums[i];
    }
    if (sums[length] < total) {
      // no subsequence
      return 0;
    }
    int len = INF;
    for (int from = 0; from < length; ++from) {
      for (int to = from + 1; to <= length; ++to) {
        const int sum = sums[to] - sums[from];
        if (sum >= total) {
          len = std::min(len, to - from);
          break;
        }
      }
    }
    return len;
  }

  int solve_subsequence(
      const int length,
      const int total,
      int sequence[]) {
    // assert(length > 10);
    assert(10e9 > total);
    constexpr int INF = 1e8;

    int from = 0;
    int to = 0;
    int sum = 0;
    int len = length + 1;
    while (true) {
      // find first subsequent
      while (to < length && sum < total) {
        sum += sequence[to++];
      }
      // to == length
      if (sum < total) {
        break;
      }
      len = std::min(len, to - from);
      sum -= sequence[from++];
    }
    if (len > length) {
      // no solution
      return 0;
    }
    return len;
  }
} // namespace pccb
