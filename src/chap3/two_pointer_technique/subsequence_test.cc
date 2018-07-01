#include "chap3/two_pointer_technique/subsequence.h"
#include <gtest/gtest.h>

namespace pccb {
  TEST(solve_subsequence_simple_test, simple1)
  {
    const int length = 10;
    const int total = 15;
    int sequence[] = {
      5,
      1,
      3,
      5,
      10,
      7,
      4,
      9,
      2,
      8,
    };
    const int actual = solve_subsequence_simple(length, total, sequence);
    EXPECT_EQ(2, actual);
  }

  TEST(solve_subsequence_simple_test, simple2)
  {
    const int length = 5;
    const int total = 11;
    int sequence[] = {
      1,
      2,
      3,
      4,
      5,
    };
    const int actual = solve_subsequence_simple(length, total, sequence);
    EXPECT_EQ(3, actual);
  }

  TEST(solve_subsequence_test, simple1)
  {
    const int length = 10;
    const int total = 15;
    int sequence[] = {
      5,
      1,
      3,
      5,
      10,
      7,
      4,
      9,
      2,
      8,
    };
    const int actual = solve_subsequence(length, total, sequence);
    EXPECT_EQ(2, actual);
  }

  TEST(solve_subsequence_test, simple2)
  {
    const int length = 5;
    const int total = 11;
    int sequence[] = {
      1,
      2,
      3,
      4,
      5,
    };
    const int actual = solve_subsequence(length, total, sequence);
    EXPECT_EQ(3, actual);
  }
} // namespace pccb
