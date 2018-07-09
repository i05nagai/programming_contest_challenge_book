#include "pccb/chap2/gtest_helper.h"
#include "pccb/chap2/prime_number.h"
#include <gtest/gtest.h>
#include <map>

//example comes from p110
TEST(prime_number, is_prime)
{
    {
        const int n = 11;
        const bool actual = is_prime(n);
        EXPECT_EQ(true, actual);
    }
    {
        const int n = 53;
        const bool actual = is_prime(n);
        EXPECT_EQ(true, actual);
    }
    {
        const int n = 295297;
        const bool actual = is_prime(n);
        EXPECT_EQ(false, actual);
    }
    {
        const int n = 78498;
        const bool actual = is_prime(n);
        EXPECT_EQ(false, actual);
    }
}

//example comes from p112
TEST(prime_number, get_divisor)
{
    {
        const int n = 12;
        std::vector<int> actual = get_divisor(n);
        const std::vector<int> expect = {2, 3, 4, 6};
        std::sort(actual.begin(), actual.end());

        EXPECT_EQ(4, actual.size());
        GTEST_EXPECT_EQ_ELEMENT(expect, actual);
    }
    //prime
    {
        const int n = 11;
        const std::vector<int> actual = get_divisor(n);
        EXPECT_EQ(0, actual.size());
    }
}

//example comes from p112
TEST(prime_number, eratosthenes_sieve)
{
    {
        const int n = 11;
        const std::vector<int> actual = eratosthenes_sieve(n);
        const std::vector<int> expect = {2, 3, 5, 7, 11};
        GTEST_EXPECT_EQ_ELEMENT(expect, actual);
    }
    {
        const int n = 1000000;
        const std::vector<int> actual = eratosthenes_sieve(n);
        EXPECT_EQ(78498, actual.size());
    }
}

TEST(prime_number, get_prime_factor)
{
    {
        const int n = 11;
        std::map<int, int> actual = get_prime_factor(n);
        EXPECT_EQ(1, actual[11]);
    }
    {
        const int n = 295927;
        std::map<int, int> actual = get_prime_factor(n);
        EXPECT_EQ(1, actual[541]);
        EXPECT_EQ(1, actual[547]);
    }
}
