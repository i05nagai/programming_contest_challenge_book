#pragma once
#include <vector>

constexpr int MINIMUM_SPANNING_TREE_INF = 1000000;

struct Edge {
    explicit Edge()
    : from(0),
        to(0),
        cost(0)
    {
    }
    Edge(const int from0, const int to0, const int cost0)
    : from(from0),
        to(to0),
        cost(cost0)
    {
    }
public:
    int from;
    int to;
    int cost;
};

/**
 * @brief 
 *
 * @param cost cost[u][v] denotes cost of edge(u, v).
 *  if there is no edge, cost[u][v] must be initialized
 *  by MINIMUM_SPANNING_TREE_INF. 
 *  Adjacency matrix.
 * @param numVertex
 *
 * @return total cost of minimum spanning tree. 
 */
int prim(
    const std::vector<std::vector<int>>& cost, const int numVertex);
/**
 * @brief 
 *
 * @param cost vector of edges in graph.
 * @param numVertex
 *
 * @return total cost of minimum spanning tree.
 */
int kruskal(
    std::vector<Edge>& cost, const int numVertex);
