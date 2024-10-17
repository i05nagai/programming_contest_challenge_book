#include "pccb/chap3/dynamic_programming/fibonacci.h"
#include <algorithm>
#include <functional>
#include <iostream>
#include <cmath>
#include <vector>

namespace {
}

// 
//  F_{n+2} =  A^(n) 1
//  F_{n+1}          0

typedef long long ll;
typedef std::vector<ll> vec;
typedef std::vector<vec> mat;

mat multiply(mat& A, mat& B, int modulo) {
  mat C(A.size(), vec(A.size()));
  for (int i = 0; i < A.size(); ++i) {
    for (int j = 0; j < A.size(); ++j) {
      C[i][j] = 0;
      for (int k = 0; k < A.size(); ++k) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
  return C;
}

namespace pccb {
  // 0 <= n <= 10^(16)
  ll SolveFibonacci(
      const int n,
      const int modulo
  ) {
    mat A = {
      {1, 0},
      {0, 1},
    };
    mat mult = {
      {1, 1},
      {1, 0},
    };

    int numDigit = std::log2(n) + 1;
    for (int i = 0; i < numDigit; i++) {
      if (n >> i & 1) {
        A = multiply(A, mult, modulo);
      }
      mult = multiply(mult, mult, modulo);
    }

    return A[1][0] % modulo;
  }

  // 0 <= n <= 10^(16)
  ll SolveFibonacci2(
      const int n,
      const int modulo
  )
  {
    mat A = {
      {1, 0},
      {0, 1},
    };
    mat B = {
      {0, 0},
      {0, 0},
    };
    mat mult = {
      {1, 1},
      {1, 0},
    };
    mat cache = {
      {1, 1},
      {1, 0},
    };

    int numDigit = std::log2(n) + 1;
    for (int i = 0; i < numDigit; i++) {

      if (n >> i & 1) {
        for (int j = 0; j < 2; ++j) {
          for (int k = 0; k < 2; ++k) {
            B[j][k] = 0;
            for (int l = 0; l < 2; ++l) {
              B[j][k] = (B[j][k] + A[j][l] * cache[l][k]) % modulo;
            }
          }
        }
        for (int j = 0; j < 2; ++j) {
          for (int k = 0; k < 2; ++k) {
            A[j][k] = B[j][k];
          }
        }
      }
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) {
          cache[j][k] = 0;
          for (int l = 0; l < 2; ++l) {
            cache[j][k] = (cache[j][k] + mult[j][l] * mult[l][k]) % modulo;
          }
        }
      }
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) {
          mult[j][k] = cache[j][k];
        }
      }
    }

    return B[1][0] % modulo;

  }
} // namespace pccb


