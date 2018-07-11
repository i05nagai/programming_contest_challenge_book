#include "algorithm/segment_tree/binary_index_tree.h"
#include <gtest/gtest.h>

namespace pccb {
TEST(binary_index_tree, SolveCountBubbleSort)
{
  int data[] = {
    1, 5, 3, 4, 2
  };
  const int size = 5;
  const long long int actual = SolveCountBubbleSort(data, size);
  EXPECT_EQ(3, actual);
}

TEST(binary_index_tree_test, binary_index_tree)
{
  int data[] = {
    1, 5, 3, 4, 2
  };
  const int size = 5;
  int tree[size];
  const long long int actual = InitBinaryIndexTree(tree, data, size);
  EXPECT_EQ(3, actual);
}
} // namespace pccb