#pragma once
#include <utility>
#include <cmath>
#include <vector>
#include <iostream>

namespace {
  constexpr double EPS = 1e-10;
} // namespace

namespace pccb {
  typedef std::pair<double, double> Point;

  inline double Add(const double left, const double right) {
    if (std::abs(left + right) < ::EPS * (std::abs(left) + std::abs(right))) {
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

  inline Point operator-(const Point& p) {
    return Point(-p.first, -p.second);
  }

  inline Point operator*(const double& value, const Point& p) {
    return Point(value * p.first, value * p.second);
  }

  inline bool operator==(const Point& p1, const Point& p2) {
    return p1.first == p2.first && p1.second == p2.second;
  }

  inline std::ostream& operator<<(std::ostream& os, const Point& target)
  {
    os << "(" << target.first << ", " << target.second << ")";
    return os;
  }

  inline double InnerProduct(const Point& p1, const Point& p2) {
    return Add(p1.first * p2.first, p1.second * p2.second);
  }

  inline double CrossProduct(const Point& p1, const Point& p2) {
    return Add(p1.first * p2.second, - p1.second * p2.first);
  }

  inline double Norm(const Point& p1, const Point& p2) {
    const Point& p = p1 - p2;
    return std::sqrt(InnerProduct(p, p));
  }

  inline double Distance(const Point& p1, const Point& p2) {
    return Norm(p1, p2);
  }

  inline bool CompareDictionaryOrder(const Point& p1, const Point& p2) {
    if (p1.first != p2.first) {
      return p1.first < p2.first;
    }
    return p1.second < p2.second;
  }

  inline std::vector<Point> ConvexHull(std::vector<Point> points) {
    std::vector<Point> convex_hull(2 * points.size());
    int k = 0;

    std::sort(points.begin(), points.end(), CompareDictionaryOrder);
    // lower part of convex_hull
    for (int i = 0; i < points.size(); ++i) {
      while (k > 1 && CrossProduct(convex_hull[k - 1] - convex_hull[k - 2], points[i] - convex_hull[k - 1]) <= 0) {
        k--;
      }
      convex_hull[k++] = points[i];
    }
    // upper part of convex_hull
    for (int i = points.size() - 2, t = k; i >= 0; --i) {
      while (k > t && CrossProduct(convex_hull[k - 1] - convex_hull[k - 2], points[i] - convex_hull[k - 1]) <= 0) {
        k--;
      }
      convex_hull[k++] = points[i];
    }
    convex_hull.resize(k - 1);
    std::sort(convex_hull.begin(), convex_hull.end(), CompareDictionaryOrder);
    return convex_hull;
  }
} // namespace pccb


