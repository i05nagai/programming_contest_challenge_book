#include "chap2/minimum_spanning_tree.h"
#include <gtest/gtest.h>

// test comes from p99
TEST(minimum_spanning_tree, prim)
{
    const int numVertex = 7;
    std::vector<std::vector<int>> cost(numVertex);

    for (int v = 0; v < numVertex; ++v) {
        cost[v].resize(numVertex);
    }

    cost[0][1] = 10;
    cost[0][2] = 2;
    cost[1][0] = 10;
    cost[1][3] = 5;
    cost[2][0] = 2;
    cost[2][3] = 7;
    cost[2][4] = 3;
    cost[2][6] = 1;
    cost[3][1] = 5;
    cost[3][2] = 7;
    cost[3][4] = 1;
    cost[3][5] = 8;
    cost[4][2] = 3;
    cost[4][3] = 1;
    cost[4][5] = 5;
    cost[5][3] = 8;
    cost[5][4] = 5;
    cost[6][2] = 1;

    for (int i = 0; i < numVertex; ++i) {
        for (int j = 0; j < numVertex; ++j) {
            if (cost[i][j] == 0) {
                cost[i][j] = MINIMUM_SPANNING_TREE_INF;
            }
        }
    }

    const int totalCost = prim(cost, numVertex);
    EXPECT_EQ(17, totalCost);
}

// test comes from p99
TEST(minimum_spanning_tree, kruskal)
{
    const int numVertex = 7;
    std::vector<Edge> cost(18);

    Edge edge1(0, 1, 10);
    Edge edge2(0, 2, 2);
    Edge edge3(1, 0, 10);
    Edge edge4(1, 3, 5);
    Edge edge5(2, 0, 2);
    Edge edge6(2, 3, 7);
    Edge edge7(2, 4, 3);
    Edge edge8(2, 6, 1);
    Edge edge9(3, 1, 5);
    Edge edge10(3, 2, 7);
    Edge edge11(3, 4, 1);
    Edge edge12(3, 5, 8);
    Edge edge13(4, 2, 3);
    Edge edge14(4, 3, 1);
    Edge edge15(4, 5, 5);
    Edge edge16(5, 3, 8);
    Edge edge17(5, 4, 5);
    Edge edge18(6, 2, 1);
    cost.push_back(edge1);
    cost.push_back(edge2);
    cost.push_back(edge3);
    cost.push_back(edge4);
    cost.push_back(edge5);
    cost.push_back(edge6);
    cost.push_back(edge7);
    cost.push_back(edge8);
    cost.push_back(edge9);
    cost.push_back(edge10);
    cost.push_back(edge11);
    cost.push_back(edge12);
    cost.push_back(edge13);
    cost.push_back(edge14);
    cost.push_back(edge15);
    cost.push_back(edge16);
    cost.push_back(edge17);
    cost.push_back(edge18);

    const int totalCost = kruskal(cost, numVertex);
    EXPECT_EQ(17, totalCost);
}
