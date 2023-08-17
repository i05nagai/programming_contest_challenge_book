#include "pccb/chap4/slide_min.h"
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;
typedef std::vector<int> vec;
typedef std::vector<vec> mat;

namespace pccb {

void dfs(int vertex, vecor<bool>& used, mat& graph, vec& postOrder) {
  used[vertex] = true;
  for (int i = 0; i < graph[vertex].size(); ++i) {
    if (!used[graph[vertex][i]]) {
      dfs(graph[vertex][i], used, graph, postOrder);
    }
  }
  postOrder.push_back(vertex);
}

void rdfs(int vertex, int k, mat& rGraph, vector<bool>& used, vec& topologicalOrder) {
  used[vertex] = true;
  topologicalOrder[vertex] = k;
  for (int i = 0; i < rGraph[vertex].size(); ++i) {
    if (!used[rGraph[vertex][i]]) {
      rdfs(rGraph[vertex][i], k, rGraph, used, topologicalOrder);
    }
  }
}

/**
 * graph: Linked list.
 */
int strongly_connected_component(mat& graph, int numVertex)
{
  // create reverse graph
  mat rGraph(numVertex);
  for (int v = 0; v < numVertex; ++v) {
    for (int i = 0; i < graph[v].size(); ++i) {
      rGraph[graph[v][i]].push_back(v);
    }
  }

  vec postOrder;
  vector<bool> used(numVertex);
  vec topologicalOrder(numVertex);

  for (int v = 0; v < numVertex; ++v) {
    if (!used[v]) {
      dfs(v, used, graph, postOrder);
    }
  }
  fill(used.begin(), used.end(), false);
  int k = 0;
  for (int i = postOrder.size() - 1; i >= 0; i--) {
    if (!used[postOrder[i]]) {
      rdfs(postOrder[i], k++, rGraph, used, topologicalOrder);
    }
  }

  return k;
}
} // namespace pccb

