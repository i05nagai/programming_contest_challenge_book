#include "algorithm/segment_tree/binary_index_tree.h"
#include <gtest/gtest.h>

namespace pccb {
TEST(binary_index_tree_test, binary_index_tree)
{
  int data[] = {
    1, 5, 3, 4, 2,
  };
  const int size = 5;
  int tree[size + 1];
  InitBinaryIndexTree(tree, data, size);
  int expect = 0;
  for (int i = 0; i < size; ++i) {
    expect += data[i];
    const int actual = SumBinaryIndexTree(tree, i + 1);
    EXPECT_EQ(expect, actual);
  }
}
} // namespace pccb
