#include "pccb/chap2/knapsack.h"
#include <gtest/gtest.h>

TEST(knapsack, simple)
{
    const int numItem = 4;
    const int weights[] = {2, 1, 3, 2};
    const int values[] = {3, 2, 4, 2};
    const int maxWeight = 5;

    // knapsack_simple
    {
        const int actual = knapsack_simple(
            numItem, weights, values, 0, maxWeight);
        EXPECT_EQ(7, actual);
    }
    // knapsack_memoization
    {
        const int actual = knapsack_memoization(
            numItem, weights, values, 0, maxWeight);
        EXPECT_EQ(7, actual);
    }
    // knapsack_dynamic_programming
    {
        const int actual = knapsack_dynamic_programming(
            numItem, weights, values, 0, maxWeight);
        EXPECT_EQ(7, actual);
    }
}

TEST(knapsack, complicate)
{
    const int numItem = 10;
    const int weights[] = {2, 1, 3, 2, 4, 5, 6, 11, 5, 1};
    const int values[] = {3, 2, 4, 2, 3, 4, 5, 6, 10, 1};
    const int maxWeight = 9;

    const int actual = knapsack_simple(
        numItem, weights, values, 0, maxWeight);
    // knapsack_simple
    {
        const int actual = knapsack_simple(
            numItem, weights, values, 0, maxWeight);
        EXPECT_EQ(16, actual);
    }
    // knapsack_memoization
    {
        const int actual = knapsack_memoization(
            numItem, weights, values, 0, maxWeight);
        EXPECT_EQ(16, actual);
    }
    // knapsack_dynamic_programming
    {
        const int actual = knapsack_dynamic_programming(
            numItem, weights, values, 0, maxWeight);
        EXPECT_EQ(16, actual);
    }
}
