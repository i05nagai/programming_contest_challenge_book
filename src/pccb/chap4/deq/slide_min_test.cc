#include "pccb/chap4/slide_min.h"
#include <gtest/gtest.h>

#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;
typedef std::vector<int> vec;
typedef std::vector<vec> mat;

namespace pccb {
// examples are in p 151
TEST(strongly_connected_component, simple)
{
  {
    int numVertex = 12;
    vector<vector<int>> graph = {
      {},
      {2},
      {1},
      {2, 0},
      {6},
      {4, 3, 2},
      {5},
      {9},
      {7, 6},
      {8},
      {7, 9},
      {10},
    };

    const int numRegions = strongly_connected_component(graph, numVertex);
    EXPECT_EQ(6, numRegions);
  }
}
} // namespace pccb


