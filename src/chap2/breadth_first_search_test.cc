#include "chap2/breadth_first_search.h"
#include <gtest/gtest.h>

TEST(breadth_first_search, breadth_first_search1)
{
  char maze[100][100] = {
    {'#', 'S', '#', '#', '#', '#', '#', '#', '.', '#',}, 
    {'.', '.', '.', '.', '.', '.', '#', '.', '.', '#',}, 
    {'.', '#', '.', '#', '#', '.', '#', '#', '.', '#',}, 
    {'.', '#', '.', '.', '.', '.', '.', '.', '.', '.',}, 
    {'#', '#', '.', '#', '#', '.', '#', '#', '#', '#',}, 
    {'.', '.', '.', '.', '#', '.', '.', '.', '.', '#',}, 
    {'.', '#', '#', '#', '#', '#', '#', '#', '.', '#',}, 
    {'.', '.', '.', '.', '#', '.', '.', '.', '.', '.',}, 
    {'.', '#', '#', '#', '#', '.', '#', '#', '#', '.',}, 
    {'.', '.', '.', '.', '#', '.', '.', '.', 'G', '#',}, 
  };

  const int numRow = 10;
  const int numCol = 10;
  const int startRow = 0;
  const int startCol = 1;
  const int goalRow = 9;
  const int goalCol = 8;

  const int actual = breadth_first_search(
      maze, numRow, numCol, startRow, startCol, goalRow, goalCol);

  EXPECT_EQ(22, actual);
}
