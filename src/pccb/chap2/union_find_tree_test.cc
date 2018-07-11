#include "pccb/chap2/union_find_tree.h"
#include <gtest/gtest.h>

namespace pccb {
TEST(union_find_tree, simple)
{
  constexpr int numElement = 7;
  int rootNode[numElement];
  int height[numElement];
  init_union_find(rootNode, height, numElement);

  unite_group(rootNode, height, 1, 2);
  unite_group(rootNode, height, 1, 5);

  unite_group(rootNode, height, 6, 4);
  unite_group(rootNode, height, 6, 7);

  const int rootNode1 = find_root_node(rootNode, height, 2);
  const int rootNode2 = find_root_node(rootNode, height, 7);
  EXPECT_EQ(rootNode1, rootNode2);
}

TEST(union_find_tree, food_chain)
{
  constexpr int numAnimal = 100;
  constexpr int numInfo = 7;

  int types[numAnimal] = {
    1, 2, 2, 2, 1, 2, 1
  };
  int x[numAnimal] = {
    101, 1, 2, 3, 1, 3, 5
  };
  int y[numAnimal] = {
    1, 2, 3, 3, 3, 1, 5
  };
  const int actual = food_chain(types, x, y, numInfo, numAnimal);
  EXPECT_EQ(3, actual);
}
} // namespace pccb
