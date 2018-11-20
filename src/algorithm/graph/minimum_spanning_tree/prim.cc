#include "algorithm/graph/minimum_spanning_tree/prim.h"
#include <queue>
#include <utility>
#include <iostream>

namespace algorithm { namespace graph {
int prim(int num_vertex, int** cost) {
  // mincost[v]: the minimum cost of path between X and v where X is the set of vertex
  int mincost[num_vertex];
  // used[v]: v is contained in X if true, 
  bool used[num_vertex];
  for (int i = 0; i < num_vertex; ++i) {
    mincost[i] = PRIM_INF;
    used[i] = false;
  }
  mincost[0] = 0;
  // start from 0
  int v = 0;
  int total_cost = 0;
  while (true) {
    // calculate cost
    for (int u = 0; u < num_vertex; ++u) {
      mincost[u] = std::min(mincost[u], cost[v][u]);
    }
    total_cost += mincost[v];
    used[v] = true;

    v = -1;
    // find a edge whose cost is the minimum in vertice from used vertice
    for (int u = 0; u < num_vertex; ++u) {
      // min cost of u is not determined 
      // and (not found edge or cost of edge is less than)
      if (!used[u]
          && (v == -1 || mincost[u] < mincost[v])) {
        v = u;
      }
    }
    // no update
    if (v == -1) {
      break;
    }
  }
  return total_cost;
}
/*
int prim(int num_vertex, int** cost) {
  // mincost[v]: the minimum cost of path between X and v where X is the set of vertex
  int mincost[num_vertex];
  // used[v]: v is contained in X if true, 
  bool used[num_vertex];
  for (int i = 0; i < num_vertex; ++i) {
    mincost[i] = PRIM_INF;
    used[i] = false;
  }
  // start from 0
  mincost[0] = 0;
  int total_cost = 0;
  while (true) {
    int v = -1;
    // find a edge whose cost is the minimum in vertice
    
    for (int u = 0; u < num_vertex; ++u) {
      // min cost of u is not determined 
      // and (not found edge or cost of edge is less than)
      if (!used[u]
          && (v == -1 || mincost[u] < mincost[v])) {
        v = u;
      }
    }
    // not update
    if (v == -1) {
      break;
    }

    used[v] = true;
    total_cost += mincost[v];
    for (int u = 0; u < num_vertex; ++u) {
      mincost[u] = std::min(mincost[u], cost[v][u]);
      std::cout << "mincost[u]: " << mincost[u] << std::endl;
    }
    std::cout << std::endl;
  }
  return total_cost;
}
*/
} } // namespace algorithm { namespace graph {
