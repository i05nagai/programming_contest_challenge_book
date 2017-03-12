#include "chap2/dijkstra.h"
#include <algorithm>
#include <queue>
#include <vector>

void dijkstra(
    int dist[],
    const std::vector<std::vector<int>>& cost,
    const int numVertex,
    const int start)
{
    bool determined[numVertex];
    std::fill(determined, determined + numVertex, false);
    std::fill(dist, dist + numVertex, DIJKSTRA_INF);
    dist[start] = 0;

    while(true) {
        // find minimum distance in not determined vertices
        // v = argmin dist[v]
        int minVertex = -1;
        for (int v = 0; v < numVertex; ++v) {
            if (!determined[v] 
                && (minVertex == -1 ||  dist[minVertex] > dist[v])) {
                minVertex = v;
            }
        }
        // all vertex are determined 
        if (minVertex == -1) {
            break;
        }

        // update neighbor of minVertex
        for (int neighbor = 0; neighbor < numVertex; ++neighbor) {
            dist[neighbor] = std::min(
                dist[neighbor], dist[minVertex] + cost[minVertex][neighbor]);
        }
        // vertex that has minimum distance is never updated.
        determined[minVertex] = true;
    }
}

void dijkstra_fast(
    int dist[],
    std::vector<DijkstraEdge> cost[],
    const int numVertex,
    const int start)
{
    // shortest distance and vertex number
    typedef std::pair<int, int> Vertex;

    std::priority_queue<Vertex, std::vector<Vertex>, std::greater<Vertex>> queue;
    std::fill(dist, dist + numVertex, DIJKSTRA_INF);
    dist[start] = 0;
    queue.push(Vertex(0, start));

    while(!queue.empty()) {
        const Vertex vertex = queue.top();
        queue.pop();
        const int distance = vertex.first;
        const int vertexNum = vertex.second;

        // if vertex in the list is not shortest distance
        // distance has not to be updated
        if (dist[vertexNum] < distance) {
            continue;
        }
        for (int e = 0; e < cost[vertexNum].size(); ++e) {
            const DijkstraEdge edge = cost[vertexNum][e];
            // if distance is updated, it is added to updated list
            if (dist[edge.to] > dist[vertexNum] + edge.cost) {
                dist[edge.to] = dist[vertexNum] + edge.cost;
                queue.push(Vertex(dist[edge.to], edge.to));
            }
        }
    }
}

void dijkstra_with_path(
    int dist[],
    const std::vector<std::vector<int>>& cost,
    const int numVertex,
    const int start,
    int previousVertex[])
{
    bool determined[numVertex];
    std::fill(determined, determined + numVertex, false);
    std::fill(dist, dist + numVertex, DIJKSTRA_INF);
    dist[start] = 0;

    while(true) {
        // find minimum distance in not determined vertices
        // v = argmin dist[v]
        int minVertex = -1;
        for (int v = 0; v < numVertex; ++v) {
            if (!determined[v] 
                && (minVertex == -1 ||  dist[minVertex] > dist[v])) {
                minVertex = v;
            }
        }
        // all vertex are determined 
        if (minVertex == -1) {
            break;
        }

        // update neighbor of minVertex
        for (int neighbor = 0; neighbor < numVertex; ++neighbor) {
            if (dist[neighbor] > dist[minVertex] + cost[minVertex][neighbor]) {
                dist[neighbor] = dist[minVertex] + cost[minVertex][neighbor];
                previousVertex[neighbor] = minVertex;
            }
        }
        // vertex that has minimum distance is never updated.
        determined[minVertex] = true;
    }
}

std::vector<int> get_shortest_path(
    int dist[],
    const std::vector<std::vector<int>>& cost,
    const int numVertex,
    const int start,
    const int end)
{
    std::vector<int> path;
    // previousVertex[v] denotes from previousVertex[v] to v
    // previous path from start to end
    int previousVertex[numVertex];
    std::fill(previousVertex, previousVertex + numVertex, -1);
    dijkstra_with_path(dist ,cost, numVertex, start, previousVertex);

    for (int v = end; v != -1; v = previousVertex[v]) {
        path.push_back(v);
    }
    std::reverse(path.begin(), path.end());
    return path;
}

