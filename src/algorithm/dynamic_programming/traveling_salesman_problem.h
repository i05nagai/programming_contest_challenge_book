#pragma once
#include <vector>

namespace algorithm {
namespace dynamic_programming {
  const int TRAVELING_SALESMAN_PROBLEM_INF = 1e6;
  int solve_traveling_salesman_problem(std::vector<int> d[], const int num_vertex);
  int solve_traveling_salesman_problem_loop(std::vector<int> d[], const int num_vertex);
} // namespace dynamic_programming
} // namespace algorithm

