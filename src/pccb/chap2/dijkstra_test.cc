#include "pccb/chap2/dijkstra.h"
#include <gtest/gtest.h>
#include <vector>

TEST(dijkstra, simple)
{
    constexpr int numVertex = 7;
    std::vector<std::vector<int>> cost(7);
    for (std::size_t i = 0; i < numVertex; ++i) {
        cost[i].resize(7);
    }
    
    const int start = 0;
    cost[0][1] = 2;
    cost[0][2] = 5;
    cost[1][0] = 2;
    cost[1][2] = 4;
    cost[1][3] = 6;
    cost[1][4] = 10;
    cost[2][0] = 5;
    cost[2][1] = 4;
    cost[2][3] = 2;
    cost[3][1] = 6;
    cost[3][2] = 2;
    cost[3][5] = 1;
    cost[4][1] = 10;
    cost[4][5] = 3;
    cost[4][6] = 5;
    cost[5][3] = 1;
    cost[5][4] = 3;
    cost[5][6] = 9;
    cost[6][4] = 5;
    cost[6][5] = 9;
    for (std::size_t i = 0; i < numVertex; ++i) {
        for (std::size_t j = 0; j < numVertex; ++j) {
            if (cost[i][j] == 0) {
                cost[i][j] = DIJKSTRA_INF;
            }
        }
    }

    int dist[numVertex];
    dijkstra(dist, cost, numVertex, start);

    EXPECT_EQ(dist[0], 0);
    EXPECT_EQ(dist[1], 2);
    EXPECT_EQ(dist[2], 5);
    EXPECT_EQ(dist[3], 7);
    EXPECT_EQ(dist[4], 11);
    EXPECT_EQ(dist[5], 8);
    EXPECT_EQ(dist[6], 16);
}

TEST(dijkstra_fast, simple)
{
    constexpr int numVertex = 7;
    std::vector<DijkstraEdge> cost[7];
    
    const int start = 0;
    {
        DijkstraEdge edge1(1, 2);
        DijkstraEdge edge2(2, 5);
        cost[0].push_back(edge1);
        cost[0].push_back(edge2);
    }
    {
        DijkstraEdge edge1(0, 2);
        DijkstraEdge edge2(2, 4);
        DijkstraEdge edge3(3, 6);
        DijkstraEdge edge4(4, 10);
        cost[1].push_back(edge1);
        cost[1].push_back(edge2);
        cost[1].push_back(edge3);
        cost[1].push_back(edge4);
    }
    {
        DijkstraEdge edge1(0, 5);
        DijkstraEdge edge2(1, 4);
        DijkstraEdge edge3(3, 2);
        cost[2].push_back(edge1);
        cost[2].push_back(edge2);
        cost[2].push_back(edge3);
    }
    {
        DijkstraEdge edge1(1, 6);
        DijkstraEdge edge2(2, 2);
        DijkstraEdge edge3(5, 1);
        cost[3].push_back(edge1);
        cost[3].push_back(edge2);
        cost[3].push_back(edge3);
    }
    {
        DijkstraEdge edge1(1, 10);
        DijkstraEdge edge2(5, 3);
        DijkstraEdge edge3(6, 5);
        cost[4].push_back(edge1);
        cost[4].push_back(edge2);
        cost[4].push_back(edge3);
    }
    {
        DijkstraEdge edge1(3, 1);
        DijkstraEdge edge2(4, 3);
        DijkstraEdge edge3(6, 9);
        cost[5].push_back(edge1);
        cost[5].push_back(edge2);
        cost[5].push_back(edge3);
    }
    {
        DijkstraEdge edge1(4, 5);
        DijkstraEdge edge2(5, 9);
        cost[6].push_back(edge1);
        cost[6].push_back(edge2);
    }

    int dist[numVertex];
    dijkstra_fast(dist, cost, numVertex, start);

    EXPECT_EQ(dist[0], 0);
    EXPECT_EQ(dist[1], 2);
    EXPECT_EQ(dist[2], 5);
    EXPECT_EQ(dist[3], 7);
    EXPECT_EQ(dist[4], 11);
    EXPECT_EQ(dist[5], 8);
    EXPECT_EQ(dist[6], 16);
}

TEST(dijkstra, with_path)
{
    constexpr int numVertex = 7;
    std::vector<std::vector<int>> cost(7);
    for (std::size_t i = 0; i < numVertex; ++i) {
        cost[i].resize(7);
    }
    
    const int start = 0;
    const int end = 6;
    cost[0][1] = 2;
    cost[0][2] = 5;
    cost[1][0] = 2;
    cost[1][2] = 4;
    cost[1][3] = 6;
    cost[1][4] = 10;
    cost[2][0] = 5;
    cost[2][1] = 4;
    cost[2][3] = 2;
    cost[3][1] = 6;
    cost[3][2] = 2;
    cost[3][5] = 1;
    cost[4][1] = 10;
    cost[4][5] = 3;
    cost[4][6] = 5;
    cost[5][3] = 1;
    cost[5][4] = 3;
    cost[5][6] = 9;
    cost[6][4] = 5;
    cost[6][5] = 9;
    for (std::size_t i = 0; i < numVertex; ++i) {
        for (std::size_t j = 0; j < numVertex; ++j) {
            if (cost[i][j] == 0) {
                cost[i][j] = DIJKSTRA_INF;
            }
        }
    }

    int dist[numVertex];
    const std::vector<int> path = get_shortest_path(
        dist, cost, numVertex, start, end);

    EXPECT_EQ(path[0], 0);
    EXPECT_EQ(path[1], 2);
    EXPECT_EQ(path[2], 3);
    EXPECT_EQ(path[3], 5);
    EXPECT_EQ(path[4], 4);
    EXPECT_EQ(path[5], 6);
}

TEST(dijkstra, dijkstra_fast_with_path)
{
    constexpr int numVertex = 7;
    std::vector<DijkstraEdge> cost[7];
    
    const int start = 0;
    const int end = 6;
    {
        DijkstraEdge edge1(1, 2);
        DijkstraEdge edge2(2, 5);
        cost[0].push_back(edge1);
        cost[0].push_back(edge2);
    }
    {
        DijkstraEdge edge1(0, 2);
        DijkstraEdge edge2(2, 4);
        DijkstraEdge edge3(3, 6);
        DijkstraEdge edge4(4, 10);
        cost[1].push_back(edge1);
        cost[1].push_back(edge2);
        cost[1].push_back(edge3);
        cost[1].push_back(edge4);
    }
    {
        DijkstraEdge edge1(0, 5);
        DijkstraEdge edge2(1, 4);
        DijkstraEdge edge3(3, 2);
        cost[2].push_back(edge1);
        cost[2].push_back(edge2);
        cost[2].push_back(edge3);
    }
    {
        DijkstraEdge edge1(1, 6);
        DijkstraEdge edge2(2, 2);
        DijkstraEdge edge3(5, 1);
        cost[3].push_back(edge1);
        cost[3].push_back(edge2);
        cost[3].push_back(edge3);
    }
    {
        DijkstraEdge edge1(1, 10);
        DijkstraEdge edge2(5, 3);
        DijkstraEdge edge3(6, 5);
        cost[4].push_back(edge1);
        cost[4].push_back(edge2);
        cost[4].push_back(edge3);
    }
    {
        DijkstraEdge edge1(3, 1);
        DijkstraEdge edge2(4, 3);
        DijkstraEdge edge3(6, 9);
        cost[5].push_back(edge1);
        cost[5].push_back(edge2);
        cost[5].push_back(edge3);
    }
    {
        DijkstraEdge edge1(4, 5);
        DijkstraEdge edge2(5, 9);
        cost[6].push_back(edge1);
        cost[6].push_back(edge2);
    }

    int dist[numVertex];
    const std::vector<int> path = get_shortest_path_fast(
        dist, cost, numVertex, start, end);

    EXPECT_EQ(path[0], 0);
    EXPECT_EQ(path[1], 2);
    EXPECT_EQ(path[2], 3);
    EXPECT_EQ(path[3], 5);
    EXPECT_EQ(path[4], 4);
    EXPECT_EQ(path[5], 6);
}
