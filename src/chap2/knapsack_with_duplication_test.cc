#include "chap2/knapsack_with_duplication.h"
#include <gtest/gtest.h>

TEST(knapsack_with_duplication, simple)
{
    const int numItem = 3;
    const int weights[] = {3, 4, 2};
    const int values[] = {4, 5, 3};
    const int maxWeight = 7;
    const int expect = 10;
    {
        const int actual = knapsack_with_duplication(
            numItem, weights, values, maxWeight);
        EXPECT_EQ(expect, actual);
    }
    // knapsack_with_duplication_simple
    {
        const int actual = knapsack_with_duplication_simple(
            numItem, weights, values, maxWeight);
        EXPECT_EQ(expect, actual);
    }
    // knapsack_with_duplication_fast
    {
        const int actual = knapsack_with_duplication_fast(
            numItem, weights, values, maxWeight);
        EXPECT_EQ(expect, actual);
    }
    // knapsack_with_duplication_fast_reuse
    {
        const int actual = knapsack_with_duplication_fast_reuse(
            numItem, weights, values, maxWeight);
        EXPECT_EQ(expect, actual);
    }
}
