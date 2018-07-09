#include "pccb/chap2/gcj/bribe_the_prisoners.h"
#include <gtest/gtest.h>

TEST(bribe_the_prisoners, simple1)
{
  const int num_prisoner = 8;
  const int num_release = 1;
  int pos_release[num_release] = {
    1,
  };

  const int actual = bribe_the_prisoners(
      num_prisoner, pos_release, num_release);

  EXPECT_EQ(7, actual);
}

TEST(bribe_the_prisoners, simple2)
{
  const int num_prisoner = 20;
  const int num_release = 3;
  int pos_release[num_release] = {
    3, 6, 14,
  };

  const int actual = bribe_the_prisoners(
      num_prisoner, pos_release, num_release);

  // 14, 6, 3
  // 13 + 6 = 19
  // 5 + 7 = 12
  // 2 + 2 = 4
  EXPECT_EQ(35, actual);
}
