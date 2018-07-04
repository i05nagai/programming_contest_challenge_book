#include "algorithm/knapsack/knapsack.h"
#include <gtest/gtest.h>

namespace pccb {
  TEST(large_knapsack_test, simple1)
  {
    const int num_item = 4;
    long long weights[] = {
      2,
      1,
      3,
      2,
    };
    long long values[] = {
      3,
      2,
      4,
      2,
    };
    const long long weight = 5;
    const long long actual = solve_large_knapsack(
        num_item, weights, values, weight);
    EXPECT_EQ(7, actual);
  }

  TEST(large_knapsack_test, simple2)
  {
    const int num_item = 10;
    long long weights[] = {2, 1, 3, 2, 4, 5, 6, 11, 5, 1};
    long long values[] = {3, 2, 4, 2, 3, 4, 5, 6, 10, 1};
    const long long weight = 9;

    const long long actual = solve_large_knapsack(
        num_item, weights, values, weight);
    EXPECT_EQ(16, actual);
  }

  TEST(large_knapsack_test, simple3)
  {
    const int num_item = 8;
    long long weights[] = {
      2,
      1,
      3,
      2,
      1,
      1,
      1,
      1,
    };
    long long values[] = {
      3,
      2,
      4,
      2,
      2,
      2,
      2,
      2,
    };
    const long long weight = 5;
    const long long actual = solve_large_knapsack(
        num_item, weights, values, weight);
    EXPECT_EQ(10, actual);
  }
} // namespace pccb
