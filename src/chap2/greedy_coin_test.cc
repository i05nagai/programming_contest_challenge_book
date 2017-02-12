#include "chap2/greedy_coin.h"
#include <gtest/gtest.h>

TEST(greedy_coin, greedy_coin0)
{
    const int price = 620;
    const int coins[6] = {1, 5, 10, 50, 100, 500};
    const int numCoins[6] = {3, 2, 1, 3, 0, 2};

    const int actual = greedy_coin(price, coins, numCoins);
    EXPECT_EQ(6, actual);
}
