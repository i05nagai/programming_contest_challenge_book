#include "algorithm/dynamic_programming/traveling_by_stagecoach.h"
#include <iostream>
#include <bitset>

namespace algorithm {
namespace dynamic_programming {
  /**
   * @brief 
   *
   * @param d[] -1 means no edge
   * @param num_ticket
   * @param num_city
   * @param start_v
   * @param end_v
   * @param tickets[]
   *
   * @return 
   */
  double solve_traveling_by_stagecoach(
      std::vector<int> d[],
      const int num_ticket,
      const int num_city,
      const int start_v,
      const int end_v,
      int tickets[])
  {
    const double INF = 1e8;
    std::vector<double> dp[1 << num_ticket];

    for (int i = 0; i < 1 << num_ticket; ++i) {
      dp[i].resize(num_city);
      for (int j = 0; j < num_city; ++j) {
        dp[i][j] = INF;
      }
    }
    dp[(1 << num_ticket) - 1][start_v - 1] = 0.0;

    double result = INF;
    for (int ticket = (1 << num_ticket) - 1; ticket >= 0;  ticket--) {
      result = std::min(result, dp[ticket][end_v - 1]);
      for (int v = 0; v < num_city; ++v) {
        for (int t = 0; t < num_ticket; ++t) {
          // still has ticket t
          if (ticket >> t & 1) {
            for (int u = 0; u < num_city; ++u) {
              // -1 means no edge
              if (d[v][u] >= 0) {
                // cost from v to u using ticket t
                const double cost_move = dp[ticket][v] + (double)(d[v][u] / (double)tickets[t]);
                // use ticket t and already at city u
                int ticket_new = ticket & (~(1 << t));
                dp[ticket_new][u] = std::min(dp[ticket_new][u], cost_move);
              }
            }
          }
        }
      }
    }

    if (result == INF) {
      // impossible
      return -1;
    } else {
      return result;
    }
  }
} // namespace dynamic_programming
} // namespace algorithm
