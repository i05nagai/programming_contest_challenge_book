#pragma once
#include <vector>
#include <iostream>

namespace algorithm {
namespace graph {
  class MinimumCostFlowEdge {
  public:
    MinimumCostFlowEdge(
        const int f, const int t, const int cap, const int c, const int e_rev)
      :
      from(f),
      to(t),
      capacity(cap),
      cost(c),
      edge_reverse(e_rev)
      {
      }
  public:
    int from;
    int to;
    int capacity;
    int cost;
    int edge_reverse;
  };

  inline std::ostream& operator<<(std::ostream& os, const MinimumCostFlowEdge& e)
  {
    std::cout << "e.from: " << e.from << std::endl;
    std::cout << "e.to: " << e.to << std::endl;
    std::cout << "e.capacity: " << e.capacity << std::endl;
    std::cout << "e.cost: " << e.cost << std::endl;
    return os;
  }

  void MinimumCostFlowAddEdge(
      std::vector<MinimumCostFlowEdge> graph[],
      const int from,
      const int to,
      const int capacity,
      const int cost);

  int SolveMinimumCostFlow(
      std::vector<MinimumCostFlowEdge> graph[],
      const int start,
      const int end,
      const int num_vertex,
      const int flow);
} // namespace graph
} // namespace algorithm

