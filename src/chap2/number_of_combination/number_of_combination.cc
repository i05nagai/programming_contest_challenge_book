#include "chap2/number_of_combination/number_of_combination.h"

int number_of_combination(
    int num_item_type,
    int num_items[],
    int num,
    int divisor)
{
  // memo[i+1][j]
  // the number of combination choose $j$ items up to $i$-th item
  int memo[num_item_type+1][num+1];
  // initialize
  for (int i = 0; i < num_item_type+1; ++i) {
    for (int j = 0; j < num+1; ++j) {
      memo[i][j] = 0;
    }
    memo[i][0] = 1;
  }

  for (int i = 1; i < num_item_type+1; ++i) {
    for (int j = 1; j < num+1; ++j) {
      // min(j - 1, a[i-1]) = j - 1
      if (j - 1 - num_items[i-1] >= 0) {
        memo[i][j] = memo[i][j-1] + memo[i-1][j] - memo[i-1][j-1-num_items[i-1]];
      // min(j - 1, a[i-1]) = a[i-1]
      } else {
        memo[i][j] = memo[i][j-1] + memo[i-1][j];
      }
      memo[i][j] %= divisor;
    }
  }

  return memo[num_item_type][num];
}
