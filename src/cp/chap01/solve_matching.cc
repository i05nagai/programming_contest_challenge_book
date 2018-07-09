#include "cp/chap01/solve_matching.h"
#include <algorithm>
#include <cmath>

namespace cp {
  int target;
  double dist[20][20];
  double memo[1 << 16];

  double matching(const int num, int bitmask) {
    // already calcualted
    if (memo[bitmask] > -0.5) {
      return memo[bitmask];
    }
    if (bitmask == target) {
      return memo[bitmask] = 0;
    }

    double ans = 2e10;
    int p1 = 0;
    int p2 = 0;
    // find first bit
    for (p1 = 0; p1 < 2 * num; p1++) {
      if (!(bitmask & (1 << p1))) {
        break;
      }
    }
    for (p2 = p1 + 1; p2 < 2 * num; p2++) {
      if (!(bitmask & (1 << p2))) {
        const int new_bitmask = bitmask | (1 << p1) | (1 << p2);
        ans = std::min(ans, dist[p1][p2] + matching(num, new_bitmask));
      }
    }

    return memo[bitmask] = ans;
  }

  double solve_matching(const int num, int x[], int y[]) {
    for (int i = 0; i < 2 * num; ++i) {
      for (int j = 0; j < 2 * num; j++) {
        const double d = std::hypot(x[i] - x[j], y[i] - y[j]);
        dist[i][j] = d;
        dist[j][i] = d;
      }
    }

    for (int i = 0; i < (1 << 16); i++) {
      memo[i] = -1.0;
    }

    target = (1 << (2 * num)) - 1;
    return matching(num, 0);
  }
} // namespace cp
