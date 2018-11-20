#pragma once

namespace algorithm {
namespace graph {
  constexpr int PRIM_INF = 100000;
  /**
   * @brief 
   *
   * @param num_vertex
   * @param cost cost[i][j]: cost of edge from i to j
   *
   * @return 
   */
  int prim(int num_vertex, int** cost);
} // namespace graph
} // namespace algorithm

