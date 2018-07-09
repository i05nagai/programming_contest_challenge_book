#include "pccb/chap2/gcj/millionaire.h"
#include <gtest/gtest.h>

TEST(millionaire, simple1)
{
  const int num_round = 1;
  const int prob = 0.5;
  const int money = 500000;
  const double actual = millionaire(num_round, prob, money);
  EXPECT_EQ(0.5, actual);
}

TEST(millionaire, simple2)
{
  const int num_round = 3;
  const int prob = 0.75;
  const int money = 600000;
  const double actual = millionaire(num_round, prob, money);
  EXPECT_EQ(0.84375, actual);
}
