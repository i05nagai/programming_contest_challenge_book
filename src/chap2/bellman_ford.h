#pragma once

struct Edge {
    int from;
    int to;
    int cost;
};
/**
 * @brief 
 *
 * @param edges[]
 * @param dist[]
 * @param numVertex
 * @param numEdge
 * @param start start vertex.
 */
void shortest_path(
    Edge edges[],
    int dist[],
    const int numVertex,
    const int numEdge,
    const int start);
/**
 * @brief 
 *
 * @param edges[]
 * @param dist[]
 * @param numVertex
 * @param numEdge
 *
 * @return true if negative loop exists.
 */
bool find_negative_loop(
    const Edge edges[],
    int dist[],
    const int numVertex,
    const int numEdge);
