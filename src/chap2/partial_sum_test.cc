#include "chap2/partial_sum.h"
#include <gtest/gtest.h>

TEST(partial_sum, simple)
{
  const int length = 3;
  const int items[] = {3, 5, 8};
  const int nums[] = {3, 2, 2};
  const int sum = 17;

  const bool actual = partial_sum(length, items, nums, sum);
  EXPECT_EQ(true, actual);
}


TEST(partial_sum, save_memory)
{
  const int length = 3;
  const int items[] = {3, 5, 8};
  const int nums[] = {3, 2, 2};
  const int sum = 17;

  const bool actual = partial_sum_save_memory(length, items, nums, sum);
  EXPECT_EQ(true, actual);
}
