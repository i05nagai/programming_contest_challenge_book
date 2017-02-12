#include "chap2/greedy_scheduling.h"
#include <gtest/gtest.h>

TEST(greedy_scheduling, greedy_scheduling)
{
    const int numJob = 5;
    const int start[5] = {1, 2, 4, 6, 8};
    const int end[5] = {3, 5, 7, 9, 10};

    const int actual = greedy_scheduling(numJob, start, end);
    EXPECT_EQ(3, actual);
}

TEST(greedy_scheduling, greedy_scheduling1)
{
    const int numJob = 5;
    const int start[5] = {1, 2, 4, 6, 8};
    const int end[5] = {3, 5, 7, 9, 10};

    const int actual = greedy_scheduling1(numJob, start, end);
    EXPECT_EQ(3, actual);
}
