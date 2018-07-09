#include "pccb/chap2/number_of_partitioning_pattern/number_of_partitioning_pattern.h"
#include <algorithm>
#include <iostream>

int number_of_partitioning_pattern(int n, int m, int M)
{
  // memo[i]:
  // the number of partitioning pattern divide $n$ into at most $m$ groups.
  int memo[m+1][n+1];
  for (int i = 0; i < m+1; ++i) {
    for (int j = 0; j < n+1; ++j) {
      memo[i][j] = 0;
    }
  }
  memo[0][0] = 1;
  // initialize
  memo[0][0] = 1;

  for (size_t i = 1; i <= m; ++i) {
    for (size_t j = 0; j <= n; ++j) {
      if (j >= i) {
        memo[i][j] = (memo[i][j-i] + memo[i-1][j]) % M;
      } else {
        memo[i][j] = memo[i-1][j];
      }
    }
  }

  return memo[m][n];
}
