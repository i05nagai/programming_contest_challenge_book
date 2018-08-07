#include "algorithm/dynamic_programming/traveling_salesman_problem.h"
#include <iostream>

namespace algorithm {
namespace dynamic_programming {

  /**
   * @brief 
   *
   * @param d[]
   * @param num_vertex N
   * @param not_visited i-th vertex isn't visited if i-th bit is 0.
   *  All vertice is visited if all bit is 1 up to N bit.
   * @param vertex
   *
   * @return 
   */
  int do_solve(
      std::vector<int> d[],
      const int num_vertex,
      std::vector<int> dp[],
      int visit,
      int vertex) {
    // already calculated
    if (dp[visit][vertex] >= 0) {
      return dp[visit][vertex];
    }

    // visit all cities
    if (visit == (1 << num_vertex) - 1
        // back to the vertex where we starts
        && vertex == 0) {
      dp[visit][vertex] = 0;
      return dp[visit][vertex];
    }

    int min_cost = TRAVELING_SALESMAN_PROBLEM_INF;
    for (int u = 0; u < num_vertex; ++u) {
      // if vertex u is not visited
      if (!((visit >> u) & 1)) {
        // visit u
        const int visit_u = visit | (1 << u);
        const int cost = do_solve(d, num_vertex, dp, visit_u, u);
        min_cost = std::min(min_cost, cost + d[vertex][u]);
      }
    }
    dp[visit][vertex] = min_cost;
    return min_cost;
  }

  int solve_traveling_salesman_problem(
      std::vector<int> d[], const int num_vertex)
  {
    std::vector<int> dp[1 << num_vertex];

    for (int i = 0; i < 1 << num_vertex; ++i) {
      dp[i].resize(num_vertex);
      for (int j = 0; j < num_vertex; ++j) {
        dp[i][j] = -1;
      }
    }

    return do_solve(d, num_vertex, dp, 0, 0);
  }
} // namespace dynamic_programming
} // namespace algorithm
