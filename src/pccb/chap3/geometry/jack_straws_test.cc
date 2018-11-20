#include "pccb/chap3/geometry/jack_straws.h"
#include "util/gtest_util.h"
#include <gtest/gtest.h>

namespace pccb {

  TEST(jack_straws_test, simple1)
  {
    const int num_straw = 7;
    // x1, y1, x2, y2
    Line lines[] = {
      Line(Point(1, 6), Point(3, 3)),
      Line(Point(4, 6), Point(4, 9)),
      Line(Point(4, 5), Point(6, 7)),
      Line(Point(1, 4), Point(3, 5)),
      Line(Point(3, 5), Point(5, 5)),
      Line(Point(5, 2), Point(6, 3)),
      Line(Point(5, 4), Point(7, 2)),
    };

    const std::vector<std::pair<int, int>> checks = {
      {1, 4},
      {1, 6},
      {3, 3},
      {6, 7},
      {2, 3},
      {1, 3},
    };
    const std::vector<bool> actual = SolveJackStraws(num_straw, lines, checks);
    std::vector<bool> expect = {
      true,
      false,
      true,
      true,
      false,
      true,
    };
    for (int i = 0; i < expect.size(); ++i) {
      EXPECT_EQ(expect[i], actual[i]) << "failed at " << i;
    }
  }

  TEST(jack_straws_test, simple2)
  {
    const int num_straw = 2;
    // x1, y1, x2, y2
    Line lines[] = {
      Line(Point(0, 2), Point(0, 0)),
      Line(Point(0, 0), Point(0, 1)),
    };

    const std::vector<std::pair<int, int>> checks = {
      {1, 1},
      {2, 2},
      {1, 2},
    };
    const std::vector<bool> actual
      = SolveJackStraws(num_straw, lines, checks);
    std::vector<bool> expect = {
      true,
      true,
      true,
    };
    for (int i = 0; i < expect.size(); ++i) {
      EXPECT_EQ_WITH_INDEX(expect[i], actual[i], i);
    }
  }

  TEST(jack_straws_test, simple3)
  {
    const int num_straw = 4;
    // x1, y1, x2, y2
    Line lines[] = {
      Line(Point(0, 4), Point(4, 1)),
      Line(Point(0, 1), Point(2, 3)),
      Line(Point(1, 2), Point(3, 4)),
      Line(Point(1, 0), Point(2, 1)),
    };

    const std::vector<std::pair<int, int>> checks = {
      {1, 2},
      {1, 4},
      {2, 3},
      {2, 4},
    };
    const std::vector<bool> actual
      = SolveJackStraws(num_straw, lines, checks);
    std::vector<bool> expect = {
      true,
      false,
      true,
      false,
    };
    for (int i = 0; i < expect.size(); ++i) {
      EXPECT_EQ_WITH_INDEX(expect[i], actual[i], i);
    }
  }
} // namespace pccb

