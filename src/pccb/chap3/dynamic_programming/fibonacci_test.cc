#include "pccb/chap3/dynamic_programming/fibonacci.h"
#include <gtest/gtest.h>

namespace pccb {
  TEST(SolveFibonacci, Simple1)
  {
    const int n = 10;
    const int modulo = 10000;
    const long long actual = SolveFibonacci(n, modulo);
    EXPECT_EQ(55, actual);
  }

  TEST(SolveFibonacci, Simple2)
  {
    const int n = 0;
    const int modulo = 10000;
    const long long actual = SolveFibonacci(n, modulo);
    EXPECT_EQ(0, actual);
  }

  TEST(SolveFibonacci, Simple3)
  {
    const int n = 1;
    const int modulo = 10000;
    const long long actual = SolveFibonacci(n, modulo);
    EXPECT_EQ(1, actual);
  }

  TEST(SolveFibonacci, Simple4)
  {
    const int n = 2;
    const int modulo = 10000;
    const long long actual = SolveFibonacci(n, modulo);
    EXPECT_EQ(1, actual);
  }

  TEST(SolveFibonacci, Simple5)
  {
    const int n = 3;
    const int modulo = 10000;
    const long long actual = SolveFibonacci(n, modulo);
    EXPECT_EQ(2, actual);
  }
} // namespace pccb

