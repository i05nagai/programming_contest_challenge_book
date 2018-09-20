#include "algorithm/selection/median_of_medians.h"
#include <gtest/gtest.h>

namespace algorithm {
namespace selection {
  TEST(median_of_medians_test, simple1)
  {
    int array[] = {
      2,
      1,
      3,
      2,
      2,
      1,
      3,
      2,
    };
    int left0 = 0;
    int right0 = 8;
    int size = 8;
    const long long actual = MedianOfMedians(
        const int array,
        const int left0,
        const int right0,
        const int size);
    EXPECT_EQ(3, actual);
  }
} // namespace selection
} // namespace algorithm
