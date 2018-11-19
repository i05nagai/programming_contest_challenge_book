#include "pccb/chap3/graph/dual_core_cpu.h"

namespace pccb {
  class DualCoreCpuEdge {
  public:
    explicit DualCoreCpuEdge(const int f, const int t, const int c)
      : from(f),
      to(t),
      cost(c)
      {
      }
  public:
    int from;
    int to;
    int cost;
  };

  void FordFulkersonAddEdge(
      std::vector<DualCoreCpuEdge> edges[],
      const int from,
      const int to,
      const int cost) {
    edges[from].push_back(DualCoreCpuEdge(edges[to].size(), to, cost));
    edges[to].push_back(DualCoreCpuEdge(edges[from].size() - 1, from, 0));
  }

  // Depth First Search
  // edge.cost denote the remained capacity
  int FindUsableCapacity(
      std::vector<DualCoreCpuEdge> edges[],
      bool used[],
      const int from,
      const int to,
      const int flow) {
    // reach destination
    if (from == to) {
      return flow;
    }
    used[from] = true;
    for (int i = 0; i < edges[from].size(); ++i) {
      DualCoreCpuEdge& e = edges[from][i];
      // vertex e.to is not used
      // there is room for new flow
      if (!used[e.to] && e.cost > 0) {
        // move to next vertex
        const int d = FindUsableCapacity(edges, used, e.to, to, std::min(flow, e.cost));
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

  int FordFulkerson(
      std::vector<DualCoreCpuEdge> edges[],
      const int start,
      const int end,
      const int num_vertex)
  {
    bool used[num_vertex];
    int flow = 0;
    const int INF = 1e8;
    while (true) {
      for (int i = 0; i < num_vertex; ++i) {
        used[i] = false;
      }

      const int f = FindUsableCapacity(edges, used, start, end, INF);
      if (f == 0) {
        return flow;
      }
      flow += f;
    }
  }

  int SolveDualCoreCpu(
      const int num_module,
      const int num_pair,
      const std::vector<int>& cost_core_a,
      const std::vector<int>& cost_core_b,
      std::vector<int> pair[])
  {
    const int num_vertex = num_module + 2;
    const int start = num_vertex - 2;
    const int end = num_vertex - 1;
    std::vector<DualCoreCpuEdge> graph[num_vertex];
    for (int i = 0; i < num_module; ++i) {
      FordFulkersonAddEdge(graph, start, i, cost_core_a[i]);
      FordFulkersonAddEdge(graph, i, end, cost_core_b[i]);
    }
    for (int i = 0; i < num_pair; ++i) {
      const int v_a = pair[i][0] - 1;
      const int v_b = pair[i][1] - 1;
      const int w = pair[i][2];
      FordFulkersonAddEdge(graph, v_a, v_b, w);
      FordFulkersonAddEdge(graph, v_b, v_a, w);
    }

    return FordFulkerson(graph, start, end, num_vertex);
  }
} // namespace pccb


