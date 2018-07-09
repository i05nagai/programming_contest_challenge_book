#include "pccb/chap2/longest_common_subsequence.h"
#include <gtest/gtest.h>

TEST(longest_common_subsequence, simple)
{
    const int length1 = 4;
    const char str1[] = "abcd";
    const int length2 = 4;
    const char str2[] = "becd";

    const int actual = longest_common_subsequence_dynamic_programming(
        length1, str1, length2, str2);
    EXPECT_EQ(3, actual);
}
