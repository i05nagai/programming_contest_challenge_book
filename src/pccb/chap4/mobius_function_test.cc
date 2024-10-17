#include "pccb/chap4/mobius_function.h"
#include <gtest/gtest.h>

#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;
typedef std::vector<int> vec;
typedef std::vector<vec> mat;

namespace pccb {
TEST(mobius_function, simple1)
{
  {
    int n = 2;

    const int actual = mobius_function(n);
    EXPECT_EQ(650, actual);
  }

  {
    int n = 4;

    const int actual = mobius_function(n);
    EXPECT_EQ(5895, actual);
  }

  {
    int n = 15315300;

    const int actual = mobius_function(n);
    EXPECT_EQ(334, actual);
  }
}
} // namespace pccb

