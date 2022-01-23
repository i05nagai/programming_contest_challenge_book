#include "pccb/chap3/dynamic_programming/domino.h"
#include <algorithm>
#include <functional>
#include <iostream>
#include <cmath>

namespace {
  int dp[2][1 << MAX_N];
}

namespace pccb {

  double SolveDomino(
      const int n,
      const int m,
      bool color[MAX_N][MAX_M],
      int Modulo
  )
  {
    int *crt = dp[0];
    int *next = dp[1];
    crt[0] = 1;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = m - 1; j  >= 0; j--) {
        for (int used = 0; used < 1 << m; ++used) {
          // if j is used or color is black, no need to update
          if (used >> j & 1 || color[i][j]) {
            // num is the same as the case when there is no block
            next[used] = crt[used & ~(1 << j)];
          } else {
            int res = 0;
            // j + 1 is on area, j + 1 is not used, color is white
            if (j + 1 < m && !(used >> (j + 1) & 1) && !color[i][j+1]) {
              res += crt[used | 1 << (j + 1)];
            }
            // i + 1 is on area, color is white
            if (i + 1 < n && !color[i + 1][j]) {
              res += crt[used | 1 << j];
            }
            next[used] = res % Modulo;
          }
        }

        // output
        // for (int used = 0; used < 1 << m; ++used) {
        //    int n = used;
        //    std::string r = "";
        //    while(n != 0) {r = (n % 2 == 0 ? "0" :"1") + r; n /= 2;}
        //    int numDigit = m - std::floor(std::log2(used)) - 1;
        //    if (used == 0) {
        //      numDigit = m;
        //    }
        //    r = std::string(numDigit, '0') + r;
        //    std::cout << r << ": " << next[used] << std::endl;
        // }
        // std::cout << std::endl;

        std::swap(next, crt);
      }
    }

    return crt[0];
  }
} // namespace pccb

