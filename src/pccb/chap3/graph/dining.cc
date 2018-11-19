#include "pccb/chap3/graph/dining.h"

namespace pccb {
  class DirectedEdge {
  public:
    explicit DirectedEdge(const int f, const int t, const int c)
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
      std::vector<DirectedEdge> edges[],
      const int from,
      const int to,
      const int cost) {
    edges[from].push_back(DirectedEdge(edges[to].size(), to, cost));
    edges[to].push_back(DirectedEdge(edges[from].size() - 1, from, 0));
  }

  // Depth First Search
  // edge.cost denote the remained capacity
  int FindUsableCapacity(
      std::vector<DirectedEdge> edges[],
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
      DirectedEdge& e = edges[from][i];
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
      std::vector<DirectedEdge> edges[],
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
  int SolveDining(
      const int num_cow,
      const int num_food,
      const int num_drink,
      std::vector<std::vector<int>>& food,
      std::vector<std::vector<int>>& drink)
  {
    const int num_vertex = num_food + num_cow + num_drink + 2;
    const int start = num_vertex - 2;
    const int end = num_vertex - 1;
    std::vector<DirectedEdge> graph[num_vertex];
    for (int i = 0; i < num_food; ++i) {
      FordFulkersonAddEdge(graph, start, i, 1);
    }
    for (int i = 0; i < num_drink; ++i) {
      const int v_drink = num_food + num_cow + i;
      FordFulkersonAddEdge(graph, v_drink, end, 1);
    }
    for (int ci = 0; ci < num_cow; ++ci) {
      const int v_cow = ci + num_food;
      for (int fi = 0; fi < food[ci].size(); ++fi) {
        const int v_food = food[ci][fi] - 1;
        FordFulkersonAddEdge(graph, v_food, v_cow, 1);
      }
      for (int di = 0; di < drink[ci].size(); ++di) {
        const int v_drink = num_food + num_cow + drink[ci][di] - 1;
        FordFulkersonAddEdge(graph, v_cow, v_drink, 1);
      }
    }

    return FordFulkerson(graph, start, end, num_vertex);
  }
} // namespace pccb

