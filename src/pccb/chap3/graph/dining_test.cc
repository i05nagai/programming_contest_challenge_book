#include "pccb/chap3/graph/dining.h"
#include <gtest/gtest.h>

namespace pccb {
  TEST(SolveDiningTest, Simple1)
  {
    const int num_cow = 4;
    const int num_food = 3;
    const int num_drink = 3;
    // num of food i-th cow likes, num of drink i-th cow likes, f1, ..., fki, 
    const std::vector<std::vector<int>> inputs = {
      {2, 2, 1, 2, 3, 1},
      {2, 2, 2, 3, 1, 2},
      {2, 2, 1, 3, 1, 2},
      {2, 1, 1, 3, 3}
    };
    std::vector<std::vector<int>> food(num_cow);
    std::vector<std::vector<int>> drink(num_cow);
    for (int i = 0; i < num_cow; ++i) {
      const int num_f = inputs[i][0];
      const int num_d = inputs[i][1];
      for (int f = 0; f < num_f; ++f) {
        food[i].push_back(inputs[i][2 + f]);
      }
      for (int d = 0; d < num_d; ++d) {
        drink[i].push_back(inputs[i][2 + num_f + d]);
      }
    }

    const int actual = SolveDining(num_cow, num_food, num_drink, food, drink);
    EXPECT_EQ(3, actual);
  }
} // namespace pccb


