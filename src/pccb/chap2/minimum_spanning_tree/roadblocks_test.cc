#include "pccb/chap2/minimum_spanning_tree/roadblocks.h"
#include <gtest/gtest.h>
#include <iostream>

// example comes from p102
TEST(roadblocks, simple)
{
    constexpr int numVertex = 4;
    constexpr int numEdge = 4;
    std::vector<std::vector<RoadblocksEdge>> cost(4);
    
    cost[0].emplace_back(1, 100);
    cost[1].emplace_back(0, 100);
    cost[1].emplace_back(2, 250);
    cost[1].emplace_back(3, 200);
    cost[2].emplace_back(1, 250);
    cost[2].emplace_back(3, 100);
    cost[3].emplace_back(1, 200);
    cost[3].emplace_back(2, 100);
    
    const int secondShortestPath = roadblocks(cost, numVertex, numEdge);
    EXPECT_EQ(450, secondShortestPath);
}

TEST(roadblocks, complex_case)
{
    constexpr int numVertex = 7;
    constexpr int numEdge = 20;
    std::vector<std::vector<RoadblocksEdge>> cost(7);
    
    const int start = 0;
    {
        RoadblocksEdge edge1(1, 2);
        RoadblocksEdge edge2(2, 5);
        cost[0].push_back(edge1);
        cost[0].push_back(edge2);
    }
    {
        RoadblocksEdge edge1(0, 2);
        RoadblocksEdge edge2(2, 4);
        RoadblocksEdge edge3(3, 6);
        RoadblocksEdge edge4(4, 10);
        cost[1].push_back(edge1);
        cost[1].push_back(edge2);
        cost[1].push_back(edge3);
        cost[1].push_back(edge4);
    }
    {
        RoadblocksEdge edge1(0, 5);
        RoadblocksEdge edge2(1, 4);
        RoadblocksEdge edge3(3, 2);
        cost[2].push_back(edge1);
        cost[2].push_back(edge2);
        cost[2].push_back(edge3);
    }
    {
        RoadblocksEdge edge1(1, 6);
        RoadblocksEdge edge2(2, 2);
        RoadblocksEdge edge3(5, 1);
        cost[3].push_back(edge1);
        cost[3].push_back(edge2);
        cost[3].push_back(edge3);
    }
    {
        RoadblocksEdge edge1(1, 10);
        RoadblocksEdge edge2(5, 3);
        RoadblocksEdge edge3(6, 5);
        cost[4].push_back(edge1);
        cost[4].push_back(edge2);
        cost[4].push_back(edge3);
    }
    {
        RoadblocksEdge edge1(3, 1);
        RoadblocksEdge edge2(4, 3);
        RoadblocksEdge edge3(6, 9);
        cost[5].push_back(edge1);
        cost[5].push_back(edge2);
        cost[5].push_back(edge3);
    }
    {
        RoadblocksEdge edge1(4, 5);
        RoadblocksEdge edge2(5, 9);
        cost[6].push_back(edge1);
        cost[6].push_back(edge2);
    }

    const int secondShortestPath = roadblocks(cost, numVertex, numEdge);
    EXPECT_EQ(17, secondShortestPath);
}
