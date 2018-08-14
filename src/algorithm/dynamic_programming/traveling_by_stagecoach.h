#pragma once
#include <vector>

namespace algorithm {
namespace dynamic_programming {
  double solve_traveling_by_stagecoach(
      std::vector<int> d[],
      const int num_ticket,
      const int num_city,
      const int start_v,
      const int end_v,
      int tickets[]);
} // namespace dynamic_programming
} // namespace algorithm
