#include "algorithm/segment_tree/range_minimum_query.h"
#include <vector>
#include <gtest/gtest.h>

namespace pccb {
TEST(range_minimum_query, simple)
{
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
  const int size = range_minimum_query_get_size(data.size());
  int tree[2 * size - 1];
  range_minimum_query_init(tree, size);
  for (int i = 0; i < data.size(); ++i) {
    range_minimum_query_update(tree, size, i, data[i]);
  }

  const int actual = range_minimum_query_query(tree, data.size());
  EXPECT_EQ(1, actual);
}
} // namespace pccb
