#include "chap2/greedy_best_cow_line.h"
#include <gtest/gtest.h>

TEST(greedy_best_cow_line, greedy_best_cow_line)
{
    const std::string word("ACDBCB");
    std::string answer = greedy_best_cow_line(word);
    EXPECT_EQ("ABCBCD", answer);
}
