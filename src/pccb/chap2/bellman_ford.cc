#include "pccb/chap2/bellman_ford.h"
#include <algorithm>

void shortest_path(
    Edge edges[],
    int dist[],
    const int numVertex,
    const int numEdge,
    const int start)
{
    constexpr int INF = 100000;
    for (int v = 0; v < numVertex; ++v) {
        dist[v] = INF;
    }

    dist[start] = 0;
    while (true) {
        bool isUpdated = false;
        // find minimum
        for (int e = 0; e < numEdge; ++e) {
            const Edge edge = edges[e];
            // d[edge.to] =  min(dist[edge.from] + edge.cost)
            if (dist[edge.to] > dist[edge.from] + edge.cost) {
                dist[edge.to] = dist[edge.from] + edge.cost;
                isUpdated = true;
            }
        }
        if (!isUpdated) {
            break;
        }
    }
}

bool find_negative_loop(
    const Edge edges[],
    int dist[],
    const int numVertex,
    const int numEdge) 
{
    memset(dist, 0, sizeof(dist));
    
    for (int i = 0; i < numVertex; ++i) {
        for (int e = 0; e < numEdge; ++e ) {
            const Edge edge = edges[e];
            if (dist[edge.to] > dist[edge.from] + edge.cost) {
                // update numVertex times that means there is negative loop.
                if (i == numVertex - 1) {
                    return true;
                }
            }
        }
    }

    return false;
}
