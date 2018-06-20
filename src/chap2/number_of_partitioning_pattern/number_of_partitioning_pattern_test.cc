#include "chap2/number_of_partitioning_pattern/number_of_partitioning_pattern.h"
#include <gtest/gtest.h>

TEST(number_of_partitioning_pattern, simple1)
{
  constexpr int num_item = 4;
  constexpr int num_partition = 3;
  constexpr int divisor = 10000;
  const int actual = number_of_partitioning_pattern(
      num_item, num_partition, divisor);
  EXPECT_EQ(4, actual);
}
