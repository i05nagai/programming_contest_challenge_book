#include "pccb/chap2/minimum_scalar_product.h"
#include <gtest/gtest.h>

// exmamples are in p117
TEST(minimum_scalar_product, simple)
{
    {
        const int numElements = 3;
        int v1[] = {
            1, 3, -5
        };
        int v2[] = {
            -2, 4, 1
        };
        long long int actual = minimum_scalar_product(v1, v2, numElements);
        EXPECT_EQ(-25, actual);
    }
    {
        const int numElements = 5;
        int v1[] = {
            1, 2, 3, 4, 5
        };
        int v2[] = {
            1, 0, 1, 0, 1
        };
        long long int actual = minimum_scalar_product(v1, v2, numElements);
        EXPECT_EQ(6, actual);
    }
}
