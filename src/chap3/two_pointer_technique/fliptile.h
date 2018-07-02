#pragma once
#include <vector>
#include <utility>

namespace pccb {
  std::pair<std::vector<std::vector<int>>, int> solve_fliptile(
      const int row,
      const int col,
      const std::vector<std::vector<int>>& tiles);
} // namespace pccb
