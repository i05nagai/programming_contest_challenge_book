#include "pccb/chap2/minimum_spanning_tree/prim.h"
#include <queue>

int prim(int num_vertex, int** cost, int mincost[]) {
  // cost[i][j]: cost of edge from i to j

  // included by the minimum spanning tree
  bool used[num_vertex];
  std::fill(used, used + num_vertex, false)
  std::priority_queue<int> qs;
  // Pair(cost, vertex)
  typedef Pair std::pair<int, int>;

  int total_cost = 0;
  qs.push(Pair(0, 0));
  for (int i = 0; i < num_vertex; ++i) {
    const Pair q = qs.top();
    qs.pop();
    const int v = q.second;

    used[v] = true;
    for (int vv = 0; vv < num_vertex; ++vv) {
      if (!used[vv] && cost[v][vv] != PRIM_INF) {
        qs.push(Pari(cost[v][vv], vv));
      }
    }
    // add cost
    const int c = q.first;
    total_cost += c;
  }

  return total_cost;
}
