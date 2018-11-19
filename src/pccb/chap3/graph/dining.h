#pragma once
#include <vector>

namespace pccb {
  int SolveDining(
      const int num_cow,
      const int num_food,
      const int num_drink,
      std::vector<std::vector<int>>& food,
      std::vector<std::vector<int>>& drink);
} // namespace pccb

