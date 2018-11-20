#include "pccb/chap3/graph/dual_core_cpu.h"
#include <gtest/gtest.h>

namespace pccb {
  TEST(SolveDualCoreCpuTest, Simple1)
  {
    const int num_module = 3;
    const int num_pair = 1;
    const std::vector<std::string> room = {
    };
    std::vector<int> cost_core_a = {
      1, 2, 10
    };
    std::vector<int> cost_core_b = {
      10, 10, 3
    };
    std::vector<int> pair[] = {
      {2, 3, 1000},
    };

    const int actual = SolveDualCoreCpu(
        num_module, num_pair, cost_core_a, cost_core_b, pair);
    EXPECT_EQ(13, actual);
  }
} // namespace pccb
