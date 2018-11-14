#pragma once
#include <vector>

namespace pccb {
  typedef std::pair<int, int> Point;
  int SolveAsteroids(const int num_grid, const std::vector<Point>& points);
} // namespace pccb
