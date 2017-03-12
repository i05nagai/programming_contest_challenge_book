#pragma once
#include <vector>

constexpr int DIJKSTRA_INF = 10000000;

struct DijkstraEdge {
    DijkstraEdge(const int to0, const int cost0)
    : to(to0),
        cost(cost0)
    {
    }
    int to;
    int cost;
};
/**
 * @brief 
 *
 * @param dist[]
 * @param cost
 * @param numVertex
 * @param start
 */
void dijkstra(
    int dist[],
    const std::vector<std::vector<int>>& cost,
    const int numVertex,
    const int start);
/**
 * @brief 
 *
 * @param dist[]
 * @param cost[]
 * @param numVertex
 * @param start
 */
void dijkstra_fast(
    int dist[],
    std::vector<DijkstraEdge> cost[],
    const int numVertex,
    const int start);
/**
 * @brief 
 *
 * @param dist[]
 * @param cost[]
 * @param numVertex
 * @param start
 */
void dijkstra_with_path(
    int dist[],
    const std::vector<std::vector<int>>& cost,
    const int numVertex,
    const int start,
    int previousVertex[]);
/**
 * @brief 
 *
 * @param dist[]
 * @param cost[]
 * @param numVertex
 * @param start
 * @param end
 */
std::vector<int> get_shortest_path(
    int dist[],
    const std::vector<std::vector<int>>& cost,
    const int numVertex,
    const int start,
    const int end);

