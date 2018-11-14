#include "algorithm/graph/minimum_cost_flow/minimum_cost_flow.h"
#include <algorithm>
#include <iostream>

namespace algorithm {
namespace graph {
  constexpr int MINIMUM_COST_FLOW_INF = 1e6;

  void MinimumCostFlowAddEdge(
      std::vector<MinimumCostFlowEdge> graph[],
      const int from,
      const int to,
      const int capacity,
      const int cost)
  {
    const MinimumCostFlowEdge e(from, to, capacity, cost,graph[to].size());
    graph[from].push_back(e);
    const MinimumCostFlowEdge e_rev(to, from, 0, -cost, graph[from].size() - 1);
    graph[to].push_back(e_rev);
  }

  int SolveMinimumCostFlow(
      std::vector<MinimumCostFlowEdge> graph[],
      const int start,
      const int end,
      const int num_vertex,
      const int flow)
  {
    int min_cost = 0;
    int required_flow = flow;
    // cost to reach vertex from start
    int min_dist[num_vertex];
    // record vertice of path
    int prev_vertex[num_vertex];
    // record edges of path
    int prev_edge[num_vertex];
    while (required_flow > 0) {
      std::fill(min_dist, min_dist + num_vertex, MINIMUM_COST_FLOW_INF);
      min_dist[start] = 0;
      bool update = true;
      // update min_dist
      while (update) {
        update = false;
        for (int v = 0; v < num_vertex; ++v) {
          if (min_dist[v] == MINIMUM_COST_FLOW_INF) {
            continue;
          }
          for (int ei = 0; ei < graph[v].size(); ++ei) {
            const MinimumCostFlowEdge& e = graph[v][ei];
            // capacity 0 is not valid route
            if (e.capacity > 0 && min_dist[e.to] > min_dist[v] + e.cost) {
              min_dist[e.to] = min_dist[v] + e.cost;
              prev_vertex[e.to] = v;
              prev_edge[e.to] = ei;
              update = true;
            }
          }
        }
      }
      // no capacity left
      if (min_dist[end] == MINIMUM_COST_FLOW_INF) {
        return -1;
      }

      int d = required_flow;
      // find minimum capacity on the path
      for (int v = end; v != start; v = prev_vertex[v]) {
        d = std::min(d, graph[prev_vertex[v]][prev_edge[v]].capacity);
      }
      required_flow -= d;
      min_cost += d * min_dist[end];

      // reduce capacity of edges on the path
      // increase capacity of reverse edges on the path
      for (int v = end; v != start; v = prev_vertex[v]) {
        MinimumCostFlowEdge& e = graph[prev_vertex[v]][prev_edge[v]];
        e.capacity -= d;
        graph[v][e.from].capacity += d;
      }
    }
    return min_cost;

  }
} // namespace graph
} // namespace algorithm

