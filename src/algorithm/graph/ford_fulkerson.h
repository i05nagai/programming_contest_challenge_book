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

  int FordFulkerson(
      std::vector<DirectedEdge> edges[],
      const int start,
      const int end,
      const int num_edge,
      const int num_vertex);
} // namespace graph
} // namespace algorithm

