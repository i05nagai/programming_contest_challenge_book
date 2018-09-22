#include "algorithm/graph/minimum_spanning_tree/prim.h"
#include <gtest/gtest.h>
#include <algorithm>

namespace algorithm { namespace graph {
TEST(prim_test, simple1)
{
  const int num_vertex = 7;
  int** cost = new int*[num_vertex];
  for (int i = 0; i < num_vertex; ++i) {
    cost[i] = new int[num_vertex];
  }
  for (int i = 0; i < num_vertex; ++i) {
    for (int j = 0; j < num_vertex; ++j) {
      cost[i][j] = PRIM_INF;
    }
  }
  cost[0][1] = 5;
  cost[0][3] = 10;
  cost[1][2] = 8;
  cost[1][4] = 7;
  cost[1][5] = 1;
  cost[2][5] = 5;
  cost[3][4] = 2;
  cost[4][5] = 3;
  cost[4][6] = 1;
  // undirected so that copy
  for (int i = 0; i < num_vertex; ++i) {
    for (int j = 0; j < i; ++j) {
      cost[i][j] = cost[j][i];
    }
  }

  const int actual = prim(num_vertex, cost);
  const int expect = 17;
  EXPECT_EQ(expect, actual);
}
} } // namespace algorithm { namespace graph {
