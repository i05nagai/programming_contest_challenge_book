#include "algorithm/graph/matching/matching.h"

namespace algorithm { namespace graph {

int Matching(
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


