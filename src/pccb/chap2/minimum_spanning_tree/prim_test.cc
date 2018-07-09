#include "pccb/chap2/minimum_spanning_tree/prim.h"
#include <gtest/gtest.h>

TEST(prim_test, simple1)
{
  const int num_vertex = 7;
  int cost[num_vertex][num_vertex];
  std::fill(cost, cost + 2 * num_vertex, PRIM_INF);
  const int actual = prim(num_vertex, cost, mincost);

  const int expect = 19;
  EXPECT_EQ(expected, actual);
}
