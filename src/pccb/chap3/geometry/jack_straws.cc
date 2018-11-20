#include "pccb/chap3/geometry/jack_straws.h"
#include <algorithm>
#include <cmath>
#include <iostream>

namespace pccb {
  double Add(const double left, const double right) {
    if (std::abs(left + right) < 1e-10 * (std::abs(left) + std::abs(right))) {
      return 0.0;
    }
    return left + right;
  }

  inline Point operator+(const Point& p1, const Point& p2) {
    return Point(Add(p1.first, p2.first), Add(p1.second, p2.second));
  }

  inline Point operator-(const Point& p1, const Point& p2) {
    return Point(Add(p1.first, - p2.first), Add(p1.second, - p2.second));
  }

  inline Point operator*(const double& value, const Point& p) {
    return Point(value * p.first, value * p.second);
  }

  std::ostream& operator<<(std::ostream& os, const Point& target)
  {
    os << "(" << target.first << ", " << target.second << ")";
    return os;
  }

  std::ostream& operator<<(std::ostream& os, const Line& target)
  {
    os << "P: " << target.first()
      << ", P: " << target.second()
      << ", P: " << target.vector();
    return os;
  }

  double InnerProduct(const Point& p1, const Point& p2) {
    return Add(p1.first * p2.first, p1.second * p2.second);
  }

  double CrossProduct(const Point& p1, const Point& p2) {
    return Add(p1.first * p2.second, - p1.second * p2.first);
  }

  bool IsOnLine(const Line& line, const Point& p) {
    const Point left = line.first() - p;
    const Point right = line.second() - p;
    return CrossProduct(left, right) == 0.0
      && InnerProduct(left, right) <= 0.0;
  }

  Point Intersection(const Line& l1, const Line& l2) {
    // l1 and l2 must not be in parallel
    const Point& p1 = l1.first();
    const Point& p2 = l1.second();
    const Point& q1 = l2.first();
    const Point& q2 = l2.second();
    const double intercept = (CrossProduct(q2 - q1, q1 - p1)
                              / CrossProduct(q2 - q1, p2 - p1));
    return p1 + intercept * (p2 - p1);
  }

  bool IsParallel(const Line& l1, const Line& l2) {
    return CrossProduct(l1.vector(), l2.vector()) == 0.0;
  }

  bool HasSharePoint(const Line& l1, const Line& l2) {
    // in parallel
    if (IsParallel(l1, l2)) {
      return (IsOnLine(l1, l2.first())
              || IsOnLine(l1, l2.second())
              || IsOnLine(l2, l1.first())
              || IsOnLine(l2, l1.second()));
    } else {
      const Point r = Intersection(l1, l2);
      return IsOnLine(l1, r) && IsOnLine(l2, r);
    }
  }

  std::vector<bool> SolveJackStraws(
      const int num_straw, Line lines[], std::vector<std::pair<int, int>> checks)
  {
    std::vector<bool> results(checks.size());

    bool graph[num_straw][num_straw];
    for (int i = 0; i < num_straw; ++i) {
      for (int j = 0; j < num_straw; ++j) {
        graph[i][j] = false;
      }
    }

    for (int i = 0; i < num_straw; ++i) {
      graph[i][i] = true;
      for (int j = 0; j < i; j++) {
        graph[i][j] = HasSharePoint(lines[i], lines[j]);
        graph[j][i] = graph[i][j];
      }
    }

    // warshal froid
    for (int k = 0; k < num_straw; ++k) {
      for (int i = 0; i < num_straw; ++i) {
        for (int j = 0; j < num_straw; ++j) {
          graph[i][j] |= graph[i][k] && graph[k][j];
        }
      }
    }

    for (int i = 0; i < checks.size(); ++i) {
      const int line1_num = checks[i].first;
      const int line2_num = checks[i].second;
      results[i] = graph[line1_num - 1][line2_num - 1];
    }

    return results;
  }
} // namespace pccb


