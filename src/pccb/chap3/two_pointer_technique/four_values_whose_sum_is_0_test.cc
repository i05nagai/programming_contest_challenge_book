#include "pccb/chap3/two_pointer_technique/four_values_whose_sum_is_0.h"
#include <gtest/gtest.h>

namespace pccb {
  TEST(four_values_whose_sum_is_0_test, simple1)
  {
    const int num_elem = 6;
    int list_a[] = {
      -45,
      -41,
      -36,
      -36,
      26,
      -32,
    };
    int list_b[] = {
      22,
      -27,
      53,
      30,
      -38,
      -54,
    };
    int list_c[] = {
      42,
      56,
      -37,
      -75,
      -10,
      -6,
    };
    int list_d[] = {
      -16,
      30,
      77,
      -46,
      62,
      45,
    };
    const int actual = solve_four_values_whose_sum_is_0(
        num_elem, list_a, list_b, list_c, list_d);
    EXPECT_EQ(5, actual);
  }
} // namespace pccb

