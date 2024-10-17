#include "pccb/chap3/dynamic_programming/color_blocks.h"
#include <algorithm>
#include <functional>
#include <iostream>
#include <cmath>

namespace {
}

typedef long long ll;
typedef std::vector<ll> vec;
typedef std::vector<vec> mat;

namespace pccb {

  mat multiply(mat& A, mat& B, int modulo) {
    mat C(A.size(), vec(A.size()));
    for (int i = 0; i < A.size(); ++i) {
      for (int j = 0; j < A[i].size(); ++j) {
        C[i][j] = 0;
        for (int k = 0; k < A[i].size(); ++k) {
          C[i][j] += A[i][k] * B[k][j] % modulo;
        }
      }
    }
    return C;
  }

  mat pow(mat A, int n, int modulo) {
    mat B(A.size(), vec(A.size()));
    for (int i = 0; i < A.size(); ++i) {
      B[i][i] = 1;
    }
    while (n > 0) {
      if (n & 1) {
        B = multiply(B, A, modulo);
      }
      A = multiply(A, A, modulo);
      n = n >> 1;
    }
    return B;
  }

  double SolveColorBlocks(
      const int n
  ) {
    const int modulo = 10007;
    mat A = {
      {2, 1, 0},
      {2, 2, 2},
      {0, 1, 2},
    };
    A = pow(A, n, modulo);
    return A[0][0] % modulo;
  }
} // namespace pccb


