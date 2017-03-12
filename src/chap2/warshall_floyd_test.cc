#include "warshall_floyd.h"
#include <gtest/gtest.h>

TEST(warshall_floyd, simple)
{
    const int numVertex = 7;
    std::vector<std::vector<int>> dist(7);
    for (std::size_t i = 0; i < numVertex; ++i) {
        dist[i].resize(7);
    }
    
    dist[0][1] = 2;
    dist[0][2] = 5;
    dist[1][0] = 2;
    dist[1][2] = 4;
    dist[1][3] = 6;
    dist[1][4] = 10;
    dist[2][0] = 5;
    dist[2][1] = 4;
    dist[2][3] = 2;
    dist[3][1] = 6;
    dist[3][2] = 2;
    dist[3][5] = 1;
    dist[4][1] = 10;
    dist[4][5] = 3;
    dist[4][6] = 5;
    dist[5][3] = 1;
    dist[5][4] = 3;
    dist[5][6] = 9;
    dist[6][4] = 5;
    dist[6][5] = 9;
    for (size_t i = 0; i < numVertex; ++i) {
        for (size_t j = 0; j < numVertex; ++j) {
            if (i != j && dist[i][j] == 0) {
                dist[i][j] = WARSHALL_FLOYD_INF;
            }
        }
    }

    warshall_floyd(dist, numVertex);
    EXPECT_EQ(dist[0][0], 0);
    EXPECT_EQ(dist[0][1], 2);
    EXPECT_EQ(dist[0][2], 5);
    EXPECT_EQ(dist[0][3], 7);
    EXPECT_EQ(dist[0][4], 11);
    EXPECT_EQ(dist[0][5], 8);
    EXPECT_EQ(dist[0][6], 16);
}

