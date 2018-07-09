#include "pccb/chap2/knapsack2.h"
#include <gtest/gtest.h>

TEST(knapsack2, simple)
{
    const int numItem = 4;
    const int weights[] = {2, 1, 3, 2};
    const int values[] = {3, 2, 4, 2};
    const int maxWeight = 5;

    // knapsack_simple
    {
        const int actual = knapsack2(
            numItem, weights, values, maxWeight);
        EXPECT_EQ(7, actual);
    }
}
