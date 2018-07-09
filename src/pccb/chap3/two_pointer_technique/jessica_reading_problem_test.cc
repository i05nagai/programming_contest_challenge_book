#include "pccb/chap3/two_pointer_technique/jessica_reading_problem.h"
#include <gtest/gtest.h>

namespace pccb {
  TEST(jessica_reading_problem_test, simple1)
  {
    const int num_page = 5;
    int ids[] = {
      1,
      8,
      8,
      8,
      1,
    };
    const int actual = solve_jessica_reading_problem(num_page, ids);
    EXPECT_EQ(2, actual);
  }
} // namespace pccb
