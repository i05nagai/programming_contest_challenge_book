#pragma once
#include "algorithm/graph/graph.h"

namespace algorithm {
namespace graph {
  void FordFulkersonAddEdge(
      std::vector<DirectedEdge> edges[],
      const int from,
      const int to,
      const int cost);

  // edges[vertex_from][vertex_to]
  // return the maximum from start to end
  int FordFulkerson(
      std::vector<DirectedEdge> edges[],
      const int start,
      const int end,
      const int num_vertex);
} // namespace graph
} // namespace algorithm

