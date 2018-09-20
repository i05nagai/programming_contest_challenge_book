#include <algorithm>
#include <iostream>
#include <vector>
#include "algorithm/graph/ford_fulkerson.h"

namespace algorithm {
namespace graph {

  int DepthFirstSearch(
      std::vector<DirectedEdge> edges[],
      bool used[],
      const int from,
      const int to,
      const int flow) {
    if (from == to) {
      return flow;
    }
    used[from] = true;
    for (int i = 0; i < edges[from].size(); ++i) {
      DirectedEdge& e = edges[from][i];
      // there is room for new flow
      if (!used[e.to] && e.cost > 0) {
        // move to next vertex
        const int d = DepthFirstSearch(edges, used, e.to, to, std::min(flow, e.cost));
        if (d > 0) {
          // reduce capacity
          e.cost -= d;
          edges[e.to][e.from].cost += d;
          return d;
        }
      }
    }
    return 0;
  }

  void AddEdge(
      std::vector<DirectedEdge> edges[],
      const int from,
      const int to,
      const int cost) {
    edges[from].push_back(DirectedEdge(edges[to].size(), to, cost));
    edges[to].push_back(DirectedEdge(edges[from].size() - 1, from, 0));
  }

  int FordFulkerson(
      std::vector<DirectedEdge> edges[],
      const int start,
      const int end,
      const int num_edge,
      const int num_vertex)
  {
    bool used[num_vertex];
    int flow = 0;
    const int INF = 1e8;
    while (true) {
      for (int i = 0; i < num_vertex; ++i) {
        used[i] = false;
      }

      const int f = DepthFirstSearch(edges, used, start, end, INF);
      if (f == 0) {
        return flow;
      }
      flow += f;
    }
  }
} // namespace graph
} // namespace algorithm

