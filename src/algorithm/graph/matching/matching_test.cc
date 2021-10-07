#include "algorithm/graph/bipartite_matching/bipartite_matching.h"
#include <gtest/gtest.h>
#include <vector>

namespace algorithm { namespace graph {
TEST(matching_test, MatchingSimple1)
{
  const int num_computer = 3;
  const int num_work = 3;
  bool** bipartite_graph = new bool*[num_computer];
  for (int i = 0; i < num_computer; ++i) {
    bipartite_graph[i] = new bool[num_work];
    for (int j = 0; j < num_work; ++j) {
      bipartite_graph[i][j] = false;
    }
  }

  std::vector<std::vector<int>> data = {
    {0, 0},
    {0, 1},
    {1, 0},
    {1, 2},
    {2, 1},
  };
  for (int i = 0; i < data.size(); ++i) {
    bipartite_graph[data[i][0]][data[i][1]] = true;
  }
  const int actual = BipartiteMatchingFordFulkerson(
      bipartite_graph, num_computer, num_work);
  const int expect = 3;
  EXPECT_EQ(expect, actual);
}
} } // namespace algorithm { namespace graph {


