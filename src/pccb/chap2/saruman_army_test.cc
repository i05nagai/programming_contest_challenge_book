#include "pccb/chap2/saruman_army.h"
#include <gtest/gtest.h>

TEST(saruman_army, saruman_army)
{
    int numPoint = 6;
    int radius = 10;
    int points[] = {1, 7, 15, 20, 30, 50};

    const int actual = saruman_army(numPoint, radius, points);
    EXPECT_EQ(3, actual);
}

TEST(saruman_army, case00)
{
    int numPoint = 11;
    int radius = 10;
    int points[] = {1, 7, 15, 19, 20, 22, 30, 50, 55, 60, 70};

    const int actual = saruman_army(numPoint, radius, points);
    EXPECT_EQ(3, actual);
}
