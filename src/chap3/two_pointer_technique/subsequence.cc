#include "chap3/two_pointer_technique/subsequence.h"
#include <algorithm>
#include <cassert>

namespace pccb {
  int solve_subsequence(
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
    if (len == INF) {
      // no subsequence
      return 0;
    } else {
      return len;
    }
  }
} // namespace pccb
