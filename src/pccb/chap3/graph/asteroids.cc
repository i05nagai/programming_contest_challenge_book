#include "pccb/chap3/graph/asteroids.h"
#include <algorithm>

namespace pccb {
  constexpr int ASTEROIDS_EDGE_INF = 1e6;

  class AsteroidsEdge {
  public:
    AsteroidsEdge(
        const int from, const int to, const int capacity, const int cost, const int edge_reverse)
      : from_(from), to_(to), capacity_(capacity), cost_(cost), edge_reverse_(edge_reverse)
      {
      }
  public:
    int from_;
    int to_;
    int capacity_;
    int cost_;
    int edge_reverse_;
  };

  void AddEdge(
      std::vector<AsteroidsEdge> graph[],
      const int from,
      const int to,
      const int capacity,
      const int cost) {
    AsteroidsEdge e(from, to, capacity, cost, graph[to].size());
    graph[from].push_back(e);
    AsteroidsEdge e_rev(to, from, 0, -cost, graph[from].size() - 1);
    graph[to].push_back(e_rev);
  }

  int FindFlow(
      std::vector<AsteroidsEdge> graph[], bool used[], const int start, const int end, const int v, const int flow) {
    if (v == end) {
      return flow;
    }
    used[v] = true;
    for (int ei = 0; ei < graph[v].size(); ++ei) {
      AsteroidsEdge& e = graph[v][ei];
      if (!used[e.to_] && e.capacity_ > 0) {
        const int min_cap = FindFlow(
            graph, used, start, end, e.to_, std::min(flow, e.capacity_));
        if (min_cap > 0) {
          e.capacity_ -= min_cap;
          graph[e.to_][e.edge_reverse_].capacity_ += min_cap;
          return min_cap;
        }
      }
    }
    return 0;
  }

  int FordFulkerson(
      std::vector<AsteroidsEdge> graph[], const int start, const int end, const int num_vertex) {
    int flow = 0;
    bool used[num_vertex];
    while (true) {
      std::fill(used, used + num_vertex, false);
      const int flow_new = FindFlow(graph, used, start, end, start, ASTEROIDS_EDGE_INF);
      // no path having capacity
      if (flow_new == 0) {
        return flow;
      }
      flow += flow_new;
    }
  }

  int BipartiteMatching(bool** bipartite_graph, const int num_group1, const int num_group2) {
    const int num_vertex = num_group1 + num_group2 + 2;
    const int start = num_group1 + num_group2;
    const int end = num_group1 + num_group2 + 1;
    std::vector<AsteroidsEdge> graph[num_vertex];

    for (int i = 0; i < num_group1; ++i) {
      for (int j = 0; j < num_group2; ++j) {
        if (bipartite_graph[i][j]) {
          const int from = i;
          const int to = j + num_group1;
          AddEdge(graph, from, to, 1, 0);
        }
      }
    }
    for (int i = 0; i < num_group1; ++i) {
      AddEdge(graph, start, i, 1, 0);
    }
    for (int j = 0; j < num_group2; ++j) {
      AddEdge(graph, num_group1 + j, end, 1, 0);
    }

    return FordFulkerson(graph, start, end, num_vertex);
  }

  int SolveAsteroids(const int num_grid, const std::vector<Point>& asteroids)
  {
    // edge
    // vertex type1: x axis
    // vertex type2: y axis
    bool** bipartite_graph = new bool*[num_grid];
    for (int i = 0; i < num_grid; ++i) {
      bipartite_graph[i] = new bool[num_grid];
      for (int j = 0; j < num_grid; ++j) {
        bipartite_graph[i][j] = false;
      }
    }
    for (int i = 0; i < asteroids.size(); ++i) {
      const int x = asteroids[i].first - 1;
      const int y = asteroids[i].second - 1;
      bipartite_graph[x][y] = true;
    }
    const int result =  BipartiteMatching(bipartite_graph, num_grid, num_grid);
    for (int i = 0; i < num_grid; ++i) {
      delete[] bipartite_graph[i];
    }
    delete[] bipartite_graph;
    return result;
  }
} // namespace pccb
