#include <gtest/gtest.h>
#include "algorithm/dynamic_programming/traveling_salesman_problem.h"

namespace algorithm {
namespace dynamic_programming {

TEST(traveling_salesman_problem, simple1)
{
  const int num_vertex = 5;
  std::vector<int> d[num_vertex];
  for (int i = 0; i < num_vertex; ++i) {
    d[i].resize(num_vertex);
    for (int j = 0; j < num_vertex; ++j) {
      d[i][j] = 0;
    }
  }
  

  d[0][1] = 3;
  d[0][2] = TRAVELING_SALESMAN_PROBLEM_INF;
  d[0][3] = 4;
  d[0][4] = TRAVELING_SALESMAN_PROBLEM_INF;
  d[1][0] = TRAVELING_SALESMAN_PROBLEM_INF;
  d[1][2] = 5;
  d[1][3] = TRAVELING_SALESMAN_PROBLEM_INF;
  d[1][4] = TRAVELING_SALESMAN_PROBLEM_INF;
  d[2][0] = 4;
  d[2][1] = TRAVELING_SALESMAN_PROBLEM_INF;
  d[2][3] = 5;
  d[2][4] = TRAVELING_SALESMAN_PROBLEM_INF;
  d[3][0] = TRAVELING_SALESMAN_PROBLEM_INF;
  d[3][1] = TRAVELING_SALESMAN_PROBLEM_INF;
  d[3][2] = TRAVELING_SALESMAN_PROBLEM_INF;
  d[3][4] = 3;
  d[4][0] = 7;
  d[4][1] = 6;
  d[4][2] = TRAVELING_SALESMAN_PROBLEM_INF;
  d[4][3] = TRAVELING_SALESMAN_PROBLEM_INF;
  const int actual = solve_traveling_salesman_problem(d, num_vertex);
  EXPECT_EQ(22, actual);
}

TEST(traveling_salesman_problem_loop, simple1)
{
  const int num_vertex = 5;
  std::vector<int> d[num_vertex];
  for (int i = 0; i < num_vertex; ++i) {
    d[i].resize(num_vertex);
    for (int j = 0; j < num_vertex; ++j) {
      d[i][j] = 0;
    }
  }

  d[0][1] = 3;
  d[0][2] = TRAVELING_SALESMAN_PROBLEM_INF;
  d[0][3] = 4;
  d[0][4] = TRAVELING_SALESMAN_PROBLEM_INF;
  d[1][0] = TRAVELING_SALESMAN_PROBLEM_INF;
  d[1][2] = 5;
  d[1][3] = TRAVELING_SALESMAN_PROBLEM_INF;
  d[1][4] = TRAVELING_SALESMAN_PROBLEM_INF;
  d[2][0] = 4;
  d[2][1] = TRAVELING_SALESMAN_PROBLEM_INF;
  d[2][3] = 5;
  d[2][4] = TRAVELING_SALESMAN_PROBLEM_INF;
  d[3][0] = TRAVELING_SALESMAN_PROBLEM_INF;
  d[3][1] = TRAVELING_SALESMAN_PROBLEM_INF;
  d[3][2] = TRAVELING_SALESMAN_PROBLEM_INF;
  d[3][4] = 3;
  d[4][0] = 7;
  d[4][1] = 6;
  d[4][2] = TRAVELING_SALESMAN_PROBLEM_INF;
  d[4][3] = TRAVELING_SALESMAN_PROBLEM_INF;
  const int actual = solve_traveling_salesman_problem_loop(d, num_vertex);
  // FIXME
  //EXPECT_EQ(22, actual);
}
} // namespace dynamic_programming
} // namespace algorithm

