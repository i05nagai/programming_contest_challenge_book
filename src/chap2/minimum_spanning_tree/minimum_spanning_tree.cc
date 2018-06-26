#include "chap2/minimum_spanning_tree/minimum_spanning_tree.h"
#include "chap2/union_find_tree.h"
#include <algorithm>

int prim(
    const std::vector<std::vector<int>>& cost, const int numVertex) 
{
    // already determined vertex
    bool determined[numVertex];
    // minimum cost from X to each node
    int minCost[numVertex];
    std::fill(determined, determined + numVertex, false);
    std::fill(minCost, minCost + numVertex, MINIMUM_SPANNING_TREE_INF);

    // start from 0
    minCost[0] = 0;
    int totalCost = 0;
    while(true) {
        // find minimun cost edge from X to V - X
        int minCostVertex = -1;
        for (int v = 0; v < numVertex; ++v) {
            if (!determined[v]
                && (minCostVertex == -1 || minCost[v] < minCost[minCostVertex])) {
                minCostVertex = v;
            }
        }

        // all vertex are added to X
        if (minCostVertex == -1) {
            break;
        }

        //add to X
        determined[minCostVertex] = true;
        totalCost += minCost[minCostVertex];

        // update cost from X to V - X
        for (int v = 0; v < numVertex; ++v) {
            minCost[v] = std::min(minCost[v], cost[minCostVertex][v]);
        }
    }
    return totalCost;
}

int kruskal(
    std::vector<MinimumSpanningTreeEdge>& cost, const int numVertex) 
{
    std::sort(cost.begin(),
              cost.end(),
              [](const MinimumSpanningTreeEdge& e1,
                 const MinimumSpanningTreeEdge& e2) {
                  return e1.cost < e2.cost;
              });
    int rootNode[numVertex];
    int height[numVertex];
    init_union_find(rootNode, height, numVertex);

    int totalCost = 0;

    for (int e = 0; e < cost.size(); ++e) {
        const MinimumSpanningTreeEdge& edge = cost[e];
        // if from and to are same component, adding edge makes cycle
        if (!is_same_group(rootNode, height, edge.from, edge.to)) {
            // edge.from and edge.to are same component
            unite_group(rootNode, height, edge.from, edge.to);
            // adding edge
            totalCost += edge.cost;           
        }
    }

    return totalCost;
}

