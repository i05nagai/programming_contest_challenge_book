#include "algorithm/graph/bipartite_graph/bipartite_graph.h"
#include <gtest/gtest.h>

namespace algorithm { namespace graph {
TEST(bipartite_graph, simple)
{
    constexpr int numVertex = 4;
    std::vector<int> graph[numVertex];
    graph[0].push_back(1);
    graph[0].push_back(3);
    graph[1].push_back(0);
    graph[1].push_back(2);
    graph[2].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(0);
    graph[3].push_back(2);

    const bool actual = is_bipartite_graph(graph, numVertex);
    EXPECT_EQ(true, actual);
}
} } // namespace algorithm { namespace graph {
