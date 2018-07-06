#include "chap3/range_minimum_query.h"
#include <vector>
#include <gtest/gtest.h>

namespace pccb {
TEST(range_minimum_query, simple)
{
  const int size = 8;
  int tree[size * 2];
  const int new_size = range_minimum_query_init(tree, size);
  std::vector<int> data = {
    1,
    3,
    4,
    5,
    7,
    7,
    7,
    7,
  };
  for (int i = 0; i < data.size(); ++i) {
    range_minimum_query_update(tree, new_size, i, data[i]);
  }

  const int left = 1;
  const int right = 7;
  const int actual = range_minimum_query_query(tree, new_size, left, right);
  EXPECT_EQ(1, actual);
}

} // namespace pccb
