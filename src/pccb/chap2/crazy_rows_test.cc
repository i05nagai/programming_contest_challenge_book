#include "pccb/chap2/crazy_rows.h"
#include <gtest/gtest.h>

// example are in p 119
TEST(crazy_rows, simple)
{
    {
        std::vector<std::vector<int> > matrix(2);
        matrix[0] = {
            1, 0
        };
        matrix[1] = {
            1, 1
        };
        const int actual = crazy_rows(matrix);
        EXPECT_EQ(0, actual);
    }
    {
        std::vector<std::vector<int> > matrix(3);
        matrix[0] = {
            0, 0, 1
        };
        matrix[1] = {
            1, 0, 0
        };
        matrix[2] = {
            0, 1, 0
        };
        const int actual = crazy_rows(matrix);
        EXPECT_EQ(2, actual);
    }
    {
        std::vector<std::vector<int> > matrix(4);
        matrix[0] = {
            1, 1, 1, 0
        };
        matrix[1] = {
            1, 1, 0, 0
        };
        matrix[2] = {
            1, 1, 0, 0
        };
        matrix[3] = {
            1, 0, 0, 0
        };
        const int actual = crazy_rows(matrix);
        EXPECT_EQ(4, actual);
    }
}

