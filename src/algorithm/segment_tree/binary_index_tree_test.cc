#include "chap3/binary_index_tree.h"
#include <gtest/gtest.h>

TEST(binary_index_tree, count_bubble_sort)
{
    int data[] = {
        1, 5, 3, 4, 2
    };
    const int size = 5;
    const long long int actual = count_bubble_sort(data, size);
    EXPECT_EQ(3, actual);
}
