#pragma once
#include <vector>

namespace algorithm { namespace graph {
bool is_bipartitable(
    const std::vector<int> graph[],
    int vertexColor[],
    const int vertex,
    const int color);

bool is_bipartite_graph(
    const std::vector<int> graph[], const int numVertex);
} } // namespace algorithm { namespace graph {
