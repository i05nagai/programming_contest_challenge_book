#include "algorithm/graph/bipartite_matching/bipartite_matching.h"
#include "algorithm/graph/ford_fulkerson.h"

namespace algorithm { namespace graph {
//
// algorithm using FordFulerson
//
int BipartiteMatchingFordFulkerson(
    bool** biparate_graph,
    const int num_group1,
    const int num_group2)
{
  const int start = num_group1 + num_group2;
  const int end = start + 1;
  const int num_vertex = end + 1;
  std::vector<DirectedEdge> edges[num_vertex];
  for (int i = 0; i < num_group1; ++i) {
    FordFulkersonAddEdge(edges, start, i, 1);
  }
  for (int i = 0; i < num_group1; ++i) {
    for (int j = 0; j < num_group2; ++j) {
      if (biparate_graph[i][j]) {
        FordFulkersonAddEdge(edges, i, num_group1 + j, 1);
      }
    }
  }
  for (int j = 0; j < num_group2; ++j) {
    FordFulkersonAddEdge(edges, num_group1 + j, end, 1);
  }
  const int num_match = FordFulkerson(edges, start, end, num_vertex);
  return num_match;
}

//
// algorithm not using ford folkerson
// 
bool ExistPath(
    const std::vector<int> graph[],
    bool used[],
    int matched[],
    const int from) {
  used[from] = true;
  for (int i = 0; i < graph[from].size(); ++i) {
    // (from, to)
    const int to = graph[from][i];
    const int w = matched[to];
    // w < 0: not matched
    if (w < 0 || (!used[w] && ExistPath(graph, used, matched, w))) {
      matched[from] = to;
      matched[to] = from;
      return true;
    }
  }
  return false;
}

int BipartiteMatching(
    bool** biparate_graph,
    const int num_group1,
    const int num_group2) {
  const int num_vertex = num_group1 + num_group2;
  std::vector<int> graph[num_vertex];

  for (int i = 0; i < num_group1; ++i) {
    for (int j = 0; j < num_group2; ++j) {
      if (biparate_graph[i][j]) {
        const int from = i;
        const int to = j + num_group1;
        graph[from].push_back(to);
        graph[to].push_back(from);
      }
    }
  }

  bool used[num_vertex];
  int matched[num_vertex];
  for (int i = 0; i < num_vertex; ++i) {
    matched[i] = -1;
  }
  int num_match = 0;
  for (int v = 0; v < num_vertex; ++v) {
    if (matched[v] < 0) {
      std::fill(used, used + num_vertex, false);
      if (ExistPath(graph, used, matched, v)) {
        num_match++;
      }
    }
  }
  return num_match;
}
} } // namespace algorithm { namespace graph {

