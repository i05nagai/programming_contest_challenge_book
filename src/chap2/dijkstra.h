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

void dijkstra(
    int dist[],
    const std::vector<std::vector<int>>& cost,
    const int numVertex,
    const int start);

void dijkstra_fast(
    int dist[],
    std::vector<DijkstraEdge> cost[],
    const int numVertex,
    const int start);
