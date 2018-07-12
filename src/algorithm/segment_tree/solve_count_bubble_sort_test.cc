#include "algorithm/segment_tree/solve_count_bubble_sort.h"
#include <gtest/gtest.h>

namespace pccb {
TEST(binary_index_tree_test, SolveCountBubbleSortSimple1)
{
  int data[] = {
    1, 5, 3, 4, 2,
  };
  const int size = 5;
  const int actual = SolveCountBubbleSort(data, size);
  EXPECT_EQ(5, actual);
}

TEST(binary_index_tree, SolveCountBubbleSortSimple2)
{
  int data[] = {
    3, 1, 4, 2,
  };
  const int size = 4;
  const int actual = SolveCountBubbleSort(data, size);
  EXPECT_EQ(3, actual);
}
} // namespace pccb

