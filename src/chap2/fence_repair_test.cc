#include "chap2/fence_repair.h"
#include <gtest/gtest.h>

TEST(fence_repair, simple)
{
    const int numFence = 3;
    int fences[] = {8, 5, 8};

    const int actual = fence_repair(numFence, fences);
    EXPECT_EQ(34, actual);
}

TEST(fence_repair, simple1)
{
    const int numFence = 5;
    int fences[] = {1, 2, 3, 4, 5};

    const int actual = fence_repair(numFence, fences);
    EXPECT_EQ(33, actual);
}
