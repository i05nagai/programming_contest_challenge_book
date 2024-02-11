#include "pccb/chap4/deq/slide_min.h"
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
TEST(slide_min_test, simple)
{
  {
    int numVertex = 12;
    vector<vector<int>> graph = {
    };

    const int actual = slide_min(numVertex);
    EXPECT_EQ(0, actual);
  }
}
} // namespace pccb


