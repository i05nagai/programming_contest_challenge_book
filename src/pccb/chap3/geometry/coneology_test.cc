#include "pccb/chap3/geometry/coneology.h"
#include "util/gtest_util.h"
#include <gtest/gtest.h>

namespace pccb {

  TEST(coneology_test, simple1)
  {
    const int num_circle = 5;
    // x1, y1, x2, y2
    Circle circles[] = {
      Circle(0, -2, 1),
      Circle(0, 3, 3),
      Circle(0, 0, 10),
      Circle(0, 1.5, 1.0),
      Circle(50, 50, 10),
    };

    const std::vector<int> actual = SolveConeology(num_circle, circles);
    std::vector<int> expect = {
      3, 5
    };
    for (int i = 0; i < expect.size(); ++i) {
      EXPECT_EQ(expect[i], actual[i]) << "failed at " << i;
    }
  }
} // namespace pccb


