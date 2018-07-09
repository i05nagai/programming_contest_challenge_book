#include "pccb/chap3/binary_search/cable_master.h"
#include <gtest/gtest.h>

namespace pccb {
  TEST(cable_master_test, simple1)
  {
    const int num_cable = 4;
    const int num_sub_cable = 11;
    double length[] = {
      8.02,
      7.43,
      4.57,
      5.39,
    };
    const double actual = solve_cable_master(num_cable, num_sub_cable, length);
    EXPECT_NEAR(2.00, actual, 1e-2);
  }
} // namespace pccb
