#include "algorithm/graph/minimum_cost_flow/minimum_cost_flow.h"
#include <gtest/gtest.h>
#include <vector>

namespace algorithm { namespace graph {
TEST(MinimumCostFlowTest, Simple1)
{
  const int num_vertex = 5;
  std::vector<MinimumCostFlowEdge> graph[num_vertex] = {
    {},
    {},
    {},
    {},
    {},
  };

  MinimumCostFlowAddEdge(graph, 0, 1, 10, 0);
  MinimumCostFlowAddEdge(graph, 0, 2, 2, 0);
  MinimumCostFlowAddEdge(graph, 1, 2, 6, 0);
  MinimumCostFlowAddEdge(graph, 1, 3, 6, 0);
  MinimumCostFlowAddEdge(graph, 2, 4, 5, 0);
  MinimumCostFlowAddEdge(graph, 3, 2, 3, 0);
  MinimumCostFlowAddEdge(graph, 3, 4, 8, 0);

  const int actual = SolveMinimumCostFlow(graph, 0, 4, num_vertex, 0);
  EXPECT_EQ(0, actual);
}

TEST(MinimumCostFlowTest, Simple2)
{
  const int num_vertex = 5;
  std::vector<MinimumCostFlowEdge> graph[num_vertex] = {
    {},
    {},
    {},
    {},
    {},
  };

  MinimumCostFlowAddEdge(graph, 0, 1, 10, 2);
  MinimumCostFlowAddEdge(graph, 0, 2, 2, 4);
  MinimumCostFlowAddEdge(graph, 1, 2, 6, 6);
  MinimumCostFlowAddEdge(graph, 1, 3, 6, 2);
  MinimumCostFlowAddEdge(graph, 2, 4, 5, 2);
  MinimumCostFlowAddEdge(graph, 3, 2, 3, 3);
  MinimumCostFlowAddEdge(graph, 3, 4, 8, 6);

  const int actual = SolveMinimumCostFlow(graph, 0, 4, num_vertex, 9);
  EXPECT_EQ(80, actual);
}
} } // namespace algorithm { namespace graph {

