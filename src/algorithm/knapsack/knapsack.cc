#include "algorithm/knapsack/knapsack.h"
#include <algorithm>
#include <utility>

namespace pccb {
  long long solve_large_knapsack(
      const int num_item,
      long long weights[],
      const long long values[],
      const long long weight) {
    // weight, value
    typedef std::pair<long long, long long> Pair;
    constexpr long long INF = 1e17;
    const int num = num_item / 2;
    Pair wv[2 << num];

    for (int i = 0; i < (1 << num); ++i) {
      long long w = 0;
      long long v = 0;
      for (int j = 0; j < (1 << num); ++j) {
        if (i >> j & 1) {
          w += weights[j];
          v += values[j];
        }
      }
      wv[i] = Pair(w, v);
    }

    // sort by weight in ascending order
    std::sort(wv, wv + (1 << num));
    int m = 1;
    for (int i = 1; i < 1 << num; i++) {
      // value less than wv[m - 1].first is useless so skip
      if (wv[m - 1].second < wv[i].second) {
        // wv[m - 1] has low weight and lower value
        wv[m++] = wv[i];
      }
    }
    // up to m
    // wv[i].first <= wv[i + 1].first
    // wv[i].second < wv[i + 1].second

    long long total_value = 0;
    for (int i = 0; i < 1 << (num_item - num); i++) {
      long long w = 0;
      long long v = 0;
      for (int j = 0; j < num_item - num; j++) {
        if (i >> j & 1) {
          w += weights[num + j];
          v += values[num + j];
        }
      }

      if (w <= weight) {
        const Pair* lbv = std::lower_bound(wv, wv + m, Pair(weight - w, INF));
        const long long v2 = (lbv - 1)->second;
        total_value = std::max(total_value, v + v2);
      }
    }
    return total_value;
  }
} // namespace pccb
