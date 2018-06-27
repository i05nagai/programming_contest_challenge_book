#include "chap2/gcj/bribe_the_prisoners.h"
#include <cmath>
#include <algorithm>
#include <iostream>


int bribe_the_prisoners(
    const int numPrisoners,
    const int posRelease[],
    const int numReleases)
{
  constexpr int INF = 10000000;
  // dp[i][j] denotes coins needed to release prisoners from i to j (not including i and j)
  // i < j is assumed
  // answer is dp[0][numReleases + 1]
  int dp[numReleases + 1][numReleases + 2];
  // add left side and right side as released prisoners
  int mPosReleases[numReleases + 2];

  for (int i = 0; i < numReleases + 1; ++i) {
    for (int j = 0; j < numReleases + 2; ++j) {
      dp[i][j] = 0;
    }
  }
  //initialize
  for (int left = 0; left <= numReleases; ++left) {
    dp[left][left + 1] = 0;
    mPosReleases[left + 1] = posRelease[left];
  }
  mPosReleases[0] = 0;
  mPosReleases[numReleases + 1] = numPrisoners + 1;

  // calc 
  for (int length = 2; length <= numReleases + 1; ++length) {
    for (int left = 0; left + length <= numReleases + 1; ++left) {
      // calc dp[left][right]
      const int right = left + length;
      int minCoins = INF;

      // find minimum coins
      for (int k = left + 1; k < right; ++k) {
        minCoins = std::min(minCoins, dp[left][k] + dp[k][right]);
      }

      // cost of (i, j)
      // and cost to create (i, j)
      dp[left][right]
        = minCoins + (mPosReleases[right] - mPosReleases[left] - 2);
    }
  }

  return dp[0][numReleases + 1];
}
