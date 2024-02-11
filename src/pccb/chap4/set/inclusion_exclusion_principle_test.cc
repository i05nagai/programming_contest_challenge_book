#include "pccb/chap4/set/inclusion_exclusion_principle.h"
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
// examples are in p 151
TEST(inclusion_exclusion_principle, simple)
{
  {
    int n = 100;
    vector<long long> a = {
      2, 3
    };

    const int actual = inclusion_exclusion_principle(n, a);
    EXPECT_EQ(67, actual);
  }

  {
    int n = 100;
    vector<long long> a = {
      2, 3, 7
    };

    const int actual = inclusion_exclusion_principle(n, a);
    EXPECT_EQ(72, actual);
  }
}
} // namespace pccb

