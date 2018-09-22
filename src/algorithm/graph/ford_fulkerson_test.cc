#include <algorithm>
#include <vector>
#include <gtest/gtest.h>
#include "algorithm/graph/ford_fulkerson.h"

namespace algorithm {
namespace graph {
TEST(ford_fulkerson_test, simple1)
{
  const int num_edge = 7;
  const int num_vertex = 5;
  std::vector<DirectedEdge> edges[num_vertex] = {
    {},
    {},
    {},
    {},
    {},
  };

  FordFulkersonAddEdge(edges, 0, 1, 10);
  FordFulkersonAddEdge(edges, 0, 2, 2);
  FordFulkersonAddEdge(edges, 1, 2, 6);
  FordFulkersonAddEdge(edges, 1, 3, 6);
  FordFulkersonAddEdge(edges, 2, 4, 5);
  FordFulkersonAddEdge(edges, 3, 2, 3);
  FordFulkersonAddEdge(edges, 3, 4, 8);

  const int actual = FordFulkerson(edges, 0, 4, num_edge, num_vertex);
  EXPECT_EQ(11, actual);
}
} // namespace graph
} // namespace algorithm
