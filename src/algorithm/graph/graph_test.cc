#include <algorithm>
#include <vector>
#include <gtest/gtest.h>
#include "algorithm/graph/graph.h"

namespace algorithm {
namespace graph {
TEST(graph_test, directed_no_cycle1)
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

  AddEdge(edges, 0, 1, 10);
  AddEdge(edges, 0, 2, 2);
  AddEdge(edges, 1, 2, 6);
  AddEdge(edges, 1, 3, 6);
  AddEdge(edges, 2, 4, 5);
  AddEdge(edges, 3, 2, 3);
  AddEdge(edges, 3, 4, 8);

  const bool actual = IsCycle(edges, num_vertex);
  EXPECT_EQ(false, actual);
}

TEST(graph_test, directed_cycle1)
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

  AddEdge(edges, 0, 1, 10);
  AddEdge(edges, 0, 2, 2);
  AddEdge(edges, 1, 2, 6);
  AddEdge(edges, 1, 3, 6);
  AddEdge(edges, 2, 4, 5);
  AddEdge(edges, 3, 2, 3);
  AddEdge(edges, 3, 4, 8);
  AddEdge(edges, 4, 0, 2);

  const bool actual = IsCycle(edges, num_vertex);
  EXPECT_EQ(true, actual);
}
} // namespace graph
} // namespace algorithm

