#include "pccb/chap2/depth_first_search.h"
#include <gtest/gtest.h>

TEST(depth_first_searh, depth_first_search1)
{
    int array[50] = {1, 2, 4, 7};
    int size = 4;
    int total = 13;

    const bool actual = depth_first_search(array, size, total, 0, 0);
    EXPECT_TRUE(actual);
}

TEST(depth_first_searh, depth_first_search2)
{
    int array[50] = {1, 2, 4, 7};
    int size = 4;
    int total = 15;

    const bool actual = depth_first_search(array, size, total, 0, 0);
    EXPECT_FALSE(actual);
}
