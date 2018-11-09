#include "pccb/chap3/geometry/white_bird.h"
#include "util/gtest_util.h"
#include <gtest/gtest.h>

namespace pccb {

  TEST(white_bird_test, simple1)
  {
    const int num_box = 0;
    const Point pig(3, 1);
    // x1, y1, x2, y2
    Box boxes[] = {
    };

    const double velocity = 7.0;
    const bool actual = SolveWhiteBird(num_box, velocity, boxes, pig);
    EXPECT_EQ(true, actual);
  }

  TEST(white_bird_test, simple2)
  {
    const int num_box = 1;
    const Point pig(3, 1);
    // x1, y1, x2, y2
    Box boxes[] = {
      Box(Point(1, 1), Point(2, 2)),
    };

    const double velocity = 7.0;
    const bool actual = SolveWhiteBird(num_box, velocity, boxes, pig);
    EXPECT_EQ(false, actual);
  }

  TEST(white_bird_test, simple3)
  {
    const int num_box = 1;
    const Point pig(2, 2);
    // x1, y1, x2, y2
    Box boxes[] = {
      Box(Point(0, 1), Point(1, 2)),
    };

    const double velocity = 7.0;
    const bool actual = SolveWhiteBird(num_box, velocity, boxes, pig);
    EXPECT_EQ(false, actual);
  }
} // namespace pccb

