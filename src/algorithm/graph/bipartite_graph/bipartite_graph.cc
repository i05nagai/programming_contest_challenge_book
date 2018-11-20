#include "algorithm/graph/bipartite_graph/bipartite_graph.h"
#include <vector>

namespace algorithm { namespace graph {
bool is_bipartitable(
    const std::vector<int> graph[],
    int vertexColor[],
    const int vertex,
    const int color)
{
    // color vertex by color
    vertexColor[vertex] = color;

    // check all neighbors not to have same color
    for (int v = 0; v < graph[vertex].size(); ++v) {
        // neighbor has same color
        const int neighbor = graph[vertex][v];
        if (vertexColor[neighbor] == color) {
            return false;
        }
        //neighbor not yet colored
        if (vertexColor[neighbor] == 0 
            && !is_bipartitable(graph, vertexColor, neighbor, -color)) {
            return false;
        }
    }

    return true;
}

bool is_bipartite_graph(
    const std::vector<int> graph[], const int numVertex)
{
    // 1 or -1, 0 means not colored
    int vertexColor[numVertex];

    // for disconnected graph
    // if graph is connected, loop is not needed.
    for (int v = 0; v < numVertex; ++v) {
        // not yet colored
        if (vertexColor[v] == 0) {
            if (!is_bipartitable(graph, vertexColor, v, 1)) {
                return false;
            }
        }
    }
    return true;
}
} } // namespace algorithm { namespace graph {
