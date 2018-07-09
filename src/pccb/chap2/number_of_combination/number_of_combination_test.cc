#include "pccb/chap2/number_of_combination/number_of_combination.h"
#include <gtest/gtest.h>
#include <vector>

TEST(number_of_combination, simple1)
{
  constexpr int num_item_type = 3;
  constexpr int num_partition = 3;
  constexpr int divisor = 10000;
  int num_items[num_item_type];
  std::vector<int> data = {
    1, 2, 3,
  };
  std::copy(data.begin(), data.end(), num_items);
  const int actual = number_of_combination(
      num_item_type, num_items, num_partition, divisor);
  EXPECT_EQ(6, actual);
}
