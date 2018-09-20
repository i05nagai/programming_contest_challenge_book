#pragma once
#include <vector>

namespace algorithm {
namespace graph {
  class Edge {
  public:
    Edge()
    : u(0),
      v(0),
      cost(-1){
    }

    explicit Edge(const int ut, const int vt, const int ct)
    : u(ut),
      v(vt),
      cost(ct){
    }

  public:
    int u;
    int v;
    int cost;
  };

  int kruskal(
      Edge edges[],
      const int num_edge,
      const int num_vertex);
} // namespace graph
} // namespace algorithm
