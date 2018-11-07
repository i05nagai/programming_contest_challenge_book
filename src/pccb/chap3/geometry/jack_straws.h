#pragma once
#include <utility>
#include <vector>

namespace pccb {
  typedef std::pair<double, double> Point;

  class Line {
  public:
    Line(const Point p1, const Point p2)
      : p1_(p1), p2_(p2), v_(p2.first - p1.first, p2.second - p1.second)
    {
    }

    const Point& first() const {
      return p1_;
    }

    const Point& second() const {
      return p2_;
    }

    const Point& vector() const {
      return v_;
    }
  private:
    Point p1_;
    Point p2_;
    Point v_;
  };

  std::vector<bool> SolveJackStraws(
      const int num_straw, Line lines[], std::vector<std::pair<int, int>> checks);
} // namespace pccb

