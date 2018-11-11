#include "pccb/chap3/geometry/beauty_contest.h"
#include "util/gtest_util.h"
#include <gtest/gtest.h>

namespace pccb {

  TEST(beauty_contest_test, simple1)
  {
    std::vector<Point> data = {
      Point(0, 5),
      Point(1, 8),
      Point(3, 4),
      Point(5, 0),
      Point(6, 2),
      Point(6, 6),
      Point(8, 3),
      Point(8, 7),
    };
    const double actual = SolveBeautyContest(data);
    const double expect = 80.0;
    EXPECT_NEAR(expect, actual, 10e-10);
  }
} // namespace pccb



