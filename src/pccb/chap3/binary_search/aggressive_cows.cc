#include "pccb/chap3/binary_search/aggressive_cows.h"
#include <cassert>
#include <cmath>
#include <algorithm>

namespace pccb {

  bool check_aggressive_cows_condition(
      const int d,
      const int num_stall,
      const int num_cow,
      int dist[]) {
      int place = 0;
      int counter = 1;
      for (int i = 1; i < num_stall; ++i) {
        if ((dist[i] - dist[place]) >= d) {
          place = i;
          counter++;
        }
      }
      return counter >= num_cow;
  }

  int solve_aggressive_cows(
      const int num_stall,
      const int num_cow,
      int dist[])
  {
    assert(num_stall >= 2);
    assert(num_cow >= 2);
    assert(num_stall >= num_cow);
    std::sort(dist, dist + num_stall);
    // [min(dist), max(dist))
    // get max
    int lb = 0;
    int ub = (dist[num_stall - 1] - dist[0]) / (num_cow - 1);

    while (ub - lb > 1) {
      // check
      const int d = (ub + lb) / 2;
      if (check_aggressive_cows_condition(d, num_stall, num_cow, dist)) {
        // [d, ub)
        lb = d;
      } else {
        // [lb, d)
        ub = d;
      }
    }

    return lb;
  }
} // namespace pccb {
