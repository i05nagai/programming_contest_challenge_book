#include "algorithm/graph/bellman_ford/bellman_ford.h"
#include <gtest/gtest.h>

namespace algorithm { namespace graph {
TEST(bellman_ford, simple)
{
    constexpr int numVertex = 7;
    constexpr int numEdge = 20;
    Edge edges[numEdge];
    
    const int start = 0;
    edges[0].from = 0;
    edges[0].to = 1;
    edges[0].cost = 2;
    edges[1].from = 0;
    edges[1].to = 2;
    edges[1].cost = 5;
    edges[2].from = 1;
    edges[2].to = 0;
    edges[2].cost = 2;
    edges[3].from = 1;
    edges[3].to = 2;
    edges[3].cost = 4;
    edges[4].from = 1;
    edges[4].to = 3;
    edges[4].cost = 6;
    edges[5].from = 1;
    edges[5].to = 4;
    edges[5].cost = 10;
    edges[6].from = 2;
    edges[6].to = 0;
    edges[6].cost = 5;
    edges[7].from = 2;
    edges[7].to = 1;
    edges[7].cost = 4;
    edges[8].from = 2;
    edges[8].to = 3;
    edges[8].cost = 2;
    edges[9].from = 3;
    edges[9].to = 1;
    edges[9].cost = 6;
    edges[10].from = 3;
    edges[10].to = 2;
    edges[10].cost = 2;
    edges[11].from = 3;
    edges[11].to = 5;
    edges[11].cost = 1;
    edges[12].from = 4;
    edges[12].to = 1;
    edges[12].cost = 10;
    edges[13].from = 4;
    edges[13].to = 5;
    edges[13].cost = 3;
    edges[14].from = 4;
    edges[14].to = 6;
    edges[14].cost = 5;
    edges[15].from = 5;
    edges[15].to = 3;
    edges[15].cost = 1;
    edges[16].from = 5;
    edges[16].to = 4;
    edges[16].cost = 3;
    edges[17].from = 5;
    edges[17].to = 6;
    edges[17].cost = 9;
    edges[18].from = 6;
    edges[18].to = 4;
    edges[18].cost = 5;
    edges[19].from = 6;
    edges[19].to = 5;
    edges[19].cost = 9;

    int dist[numVertex];
    shortest_path(edges, dist, numVertex, numEdge, start);
    EXPECT_EQ(dist[0], 0);
    EXPECT_EQ(dist[1], 2);
    EXPECT_EQ(dist[2], 5);
    EXPECT_EQ(dist[3], 7);
    EXPECT_EQ(dist[4], 11);
    EXPECT_EQ(dist[5], 8);
    EXPECT_EQ(dist[6], 16);
}

TEST(bellman_ford, negative_loop)
{
    constexpr int numVertex = 7;
    constexpr int numEdge = 20;
    Edge edges[numEdge];
    
    const int start = 0;
    edges[0].from = 0;
    edges[0].to = 1;
    edges[0].cost = 2;
    edges[1].from = 0;
    edges[1].to = 2;
    edges[1].cost = 5;
    edges[2].from = 1;
    edges[2].to = 0;
    edges[2].cost = 2;
    edges[3].from = 1;
    edges[3].to = 2;
    edges[3].cost = 4;
    edges[4].from = 1;
    edges[4].to = 3;
    edges[4].cost = 6;
    edges[5].from = 1;
    edges[5].to = 4;
    edges[5].cost = -10; // negative
    edges[6].from = 2;
    edges[6].to = 0;
    edges[6].cost = 5;
    edges[7].from = 2;
    edges[7].to = 1;
    edges[7].cost = 4;
    edges[8].from = 2;
    edges[8].to = 3;
    edges[8].cost = 2;
    edges[9].from = 3;
    edges[9].to = 1;
    edges[9].cost = 6;
    edges[10].from = 3;
    edges[10].to = 2;
    edges[10].cost = 2;
    edges[11].from = 3;
    edges[11].to = 5;
    edges[11].cost = 1;
    edges[12].from = 4;
    edges[12].to = 1;
    edges[12].cost = 10;
    edges[13].from = 4;
    edges[13].to = 5;
    edges[13].cost = 3;
    edges[14].from = 4;
    edges[14].to = 6;
    edges[14].cost = 5;
    edges[15].from = 5;
    edges[15].to = 3;
    edges[15].cost = 1;
    edges[16].from = 5;
    edges[16].to = 4;
    edges[16].cost = 3;
    edges[17].from = 5;
    edges[17].to = 6;
    edges[17].cost = 9;
    edges[18].from = 6;
    edges[18].to = 4;
    edges[18].cost = 5;
    edges[19].from = 6;
    edges[19].to = 5;
    edges[19].cost = 9;

    int dist[numVertex];
    const bool actual = find_negative_loop(
        edges, dist, numVertex, numEdge);
    EXPECT_EQ(true, actual);
}
} } // namespace algorithm { namespace graph {
