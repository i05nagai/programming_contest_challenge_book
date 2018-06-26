#pragma once

#include <vector>

struct RoadblocksEdge {
    explicit RoadblocksEdge()
    : to(0),
        cost(0)
    {
    }
    RoadblocksEdge(const int to0, const int cost0)
    : to(to0),
        cost(cost0)
    {
    }
 public:
    int to;
    int cost;
};

/**
 * @brief 
 *
 * @param graph[] graph[v] is array of edges which v-th vertex has
 * @param numJunction number of junction that is number of vertex in the graph.
 * @param numRoad number of road that is number of edges in the graph.
 *
 * @return second shortest distance from 1-th vertex to numRoad-th vertex 
 */
int roadblocks(
    const std::vector<std::vector<RoadblocksEdge>>& graph,
    const int numJunction,
    const int numRoad);
