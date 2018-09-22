#include <algorithm>
#include <iostream>
#include <vector>
#include "algorithm/graph/ford_fulkerson.h"

namespace algorithm {
namespace graph {

  void AddEdge(
      std::vector<DirectedEdge> edges[],
      const int from,
      const int to,
      const int cost) {
    edges[from].push_back(DirectedEdge(from, to, cost));
  }

  bool DoIsCycle(
      std::vector<DirectedEdge> edges[],
      const int num_vertex,
      bool visited[],
      const int vertex) {
    if (visited[vertex]) {
      return true;
    }
    visited[vertex] = true;
    for (int i = 0; i < edges[vertex].size(); ++i) {
      const int to = edges[vertex][i].to;
      // cycle
      if (DoIsCycle(edges, num_vertex, visited, to)) {
        return true;
      }
    }
    visited[vertex] = false;
    return false;
  }

  bool IsCycle(std::vector<DirectedEdge> edges[], const int num_vertex) {
    bool visited[num_vertex];
    for (int i = 0; i < num_vertex; ++i) {
      visited[i] = false;
    }
    for (int i = 0; i < num_vertex; ++i) {
      if (DoIsCycle(edges, num_vertex, visited, i)) {
        return true;
      }
    }
    return false;
  }
} // namespace graph
} // namespace algorithm


