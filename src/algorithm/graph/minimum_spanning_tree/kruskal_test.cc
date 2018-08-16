#include <algorithm>
#include <vector>
#include <gtest/gtest.h>
#include "algorithm/graph/minimum_spanning_tree/kruskal.h"

namespace algorithm {
namespace graph {
TEST(krusal_test, simple1)
{
  std::vector<Edge> inserter = {
    Edge(0, 1, 5),
    Edge(0, 3, 10),
    Edge(1, 2, 8),
    Edge(1, 4, 6),
    Edge(1, 5, 1),
    Edge(2, 5, 5),
    Edge(3, 4, 2),
    Edge(4, 5, 3),
    Edge(4, 6, 1),
  };
  const int num_edge = inserter.size();
  const int num_vertex = 7;
  Edge edges[num_edge];
  std::copy(inserter.begin(), inserter.end(), edges);

  const int actual = kruskal(edges, num_edge, num_vertex);
  EXPECT_EQ(17, actual);
}
} // namespace graph
} // namespace algorithm
