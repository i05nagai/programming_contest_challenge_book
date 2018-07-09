#include "pccb/chap3/binary_search/lower_bound.h"
#include <gtest/gtest.h>

TEST(lower_bound_test, simple1)
{
  const int n = 5;
  int sequence[] = {
    2, 3, 3, 5, 6,
  };
  const int lower_bound = 3;

  const int actual =  find_lower_bound_index(n, sequence, lower_bound);
  EXPECT_EQ(1, actual);
}

TEST(lower_bound_test, simple2)
{
  const int n = 12;
  int sequence[] = {
    2, 3, 3, 5, 6,
    8, 9, 21, 21, 33,
    424, 1110,
  };
  const int lower_bound = 21;

  const int actual =  find_lower_bound_index(n, sequence, lower_bound);
  EXPECT_EQ(7, actual);
}

TEST(lower_bound_test, simple2_bound_first)
{
  const int n = 12;
  int sequence[] = {
    2, 3, 3, 5, 6,
    8, 9, 21, 21, 33,
    424, 1110,
  };
  const int lower_bound = 0;

  const int actual =  find_lower_bound_index(n, sequence, lower_bound);
  EXPECT_EQ(0, actual);
}

TEST(lower_bound_test, simple2_bound_last)
{
  const int n = 12;
  int sequence[] = {
    2, 3, 3, 5, 6,
    8, 9, 21, 21, 33,
    424, 1110,
  };
  const int lower_bound = 1111;

  const int actual =  find_lower_bound_index(n, sequence, lower_bound);
  EXPECT_EQ(12, actual);
}
