#include "pccb/chap3/geometry/common.h"
#include <gtest/gtest.h>

namespace pccb {
  TEST(common_test, CrossProductTest1)
  {
    Point p1(1.0, 1.0);
    Point p2(1.0, 1.0);
    const double actual = CrossProduct(p1, p2);
    const double expect = 0.0;
    EXPECT_EQ(expect, actual);
  }

  TEST(common_test, CrossProductTest2)
  {
    Point p1(1.0, 1.0);
    Point p2(2.0, 2.0);
    const double actual = CrossProduct(p1, p2);
    const double expect = 0.0;
    EXPECT_EQ(expect, actual);
  }

  TEST(common_test, CrossProductTest3)
  {
    Point p1(1.0, 1.0);
    Point p2(1.0, 0.0);
    const double actual = CrossProduct(p1, p2);
    const double expect = -1.0;
    EXPECT_EQ(expect, actual);
  }

  TEST(common_test, CrossProductTest4)
  {
    Point p1(1.0, 1.0);
    Point p2(0.0, 2.0);
    const double actual = CrossProduct(p1, p2);
    const double expect = 2.0;
    EXPECT_EQ(expect, actual);
  }

  TEST(common_test, ConvexHullTest)
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
    const std::vector<Point> actual = ConvexHull(data);
    const std::vector<Point> expect = {
      Point(0, 5),
      Point(1, 8),
      Point(5, 0),
      Point(8, 3),
      Point(8, 7),
    };
    for (int i = 0; i < expect.size(); ++i) {
      EXPECT_EQ(expect[i], actual[i]) << "failed at " << i;
    }
  }
} // namespace pccb
