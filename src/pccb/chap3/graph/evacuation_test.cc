#include "pccb/chap3/graph/evacuation.h"
#include <gtest/gtest.h>

namespace pccb {
  TEST(SolveEvacuation, Simple1)
  {
    const int x = 5;
    const int y = 5;
    const std::vector<std::string> room = {
      "XXDXX",
      "X...X",
      "D...X",
      "X...D",
      "XXXXX",
    };

    const int actual = SolveEvacuation(x, y, room);
    EXPECT_EQ(3, actual);
  }

  /*
  TEST(SolveEvacuationTest, Simple2)
  {
    const int x = 5;
    const int y = 12;
    const std::vector<std::string> room = {
      "XXXXXXXXXXXX",
      "X..........D",
      "X.XXXXXXXXXX",
      "X..........X",
      "XXXXXXXXXXXX",
    };

    const int actual = SolveEvacuation(x, y, room);
    EXPECT_EQ(21, actual);
  }

  TEST(SolveEvacuationTest, Simple3)
  {
    const int x = 5;
    const int y = 5;
    const std::vector<std::string> room = {
      "XDXXX",
      "X.X.X",
      "XX.XX",
      "D.X.X",
      "XXXDX",
    };

    const int actual = SolveEvacuation(x, y, room);
    EXPECT_EQ(-1, actual);
  }
  */
} // namespace pccb



