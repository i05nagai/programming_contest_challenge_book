#include "pccb/chap3/two_pointer_technique/face_the_right_way.h"
#include <gtest/gtest.h>

namespace pccb {
  TEST(face_the_right_way_test, simple1)
  {
    const int num_cow = 7;
    char directions[] = {
      'B',
      'B',
      'F',
      'B',
      'F',
      'B',
      'B',
    };
    const std::pair<int ,int> actual
      = solve_face_the_right_way(num_cow, directions);
    // minimum num of operations
    EXPECT_EQ(3, actual.first);
    // minimum consequent cows to turn
    EXPECT_EQ(3, actual.second);
  }
} // namespace pccb
