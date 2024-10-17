#pragma once
#include <vector>

namespace {
  const int MAX_N = 15;
  const int MAX_M = 15;
}

namespace pccb {
  // false is white,
  // true is black
  double SolveDomino(
      const int n,
      const int m,
      bool color[MAX_N][MAX_M],
      int Modulo
      );
} // namespace pccb

