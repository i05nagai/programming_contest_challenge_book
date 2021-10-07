#include "pccb/chap3/binary_search/maximize_average.h"
#include <gtest/gtest.h>

namespace pccb {
  TEST(SolveMaximizeAverage, Simple1)
  {
    const int num_choice = 2;
    const std::vector<MaximizeAverageItem> items = {
      MaximizeAverageItem(2, 2),
      MaximizeAverageItem(5, 3),
      MaximizeAverageItem(2, 1),
    };

    const double actual = SolveMaximizeAverage(num_choice, items);
    EXPECT_NEAR(0.75, actual, 1e-2);
  }
} // namespace pccb


