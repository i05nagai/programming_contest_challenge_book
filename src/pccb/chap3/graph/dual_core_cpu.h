#pragma once
#include <vector>

namespace pccb {
  int SolveDualCoreCpu(
      const int num_module,
      const int num_pair,
      const std::vector<int>& cost_core_a,
      const std::vector<int>& cost_core_b,
      std::vector<int> pair[]);
} // namespace pccb


