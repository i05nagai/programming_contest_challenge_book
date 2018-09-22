#pragma once

namespace algorithm {
namespace graph {
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

  void AddEdge(
      std::vector<DirectedEdge> edges[],
      const int from,
      const int to,
      const int cost);

  bool IsCycle(std::vector<DirectedEdge> edges[], const int num_vertex);
  bool IsCycle(std::vector<int> adj_list[]);
  // edge lists
  bool IsCycle(std::vector<DirectedEdge> edges);
} // namespace graph
} // namespace algorithm


