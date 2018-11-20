#pragma once
#include <utility>
#include <vector>

namespace pccb {
  class Circle {
  public:
    Circle(const double x, const double y, const double radius)
      : x_(x), y_(y), radius_(radius)
    {
    }

  double Radius() const {
    return radius_;
  }

  double X() const {
    return x_;
  }

  double Y() const {
    return y_;
  }

  // (x, y) is contained in this circle
  bool Contain(const double x, const double y) const {
    const double dx = x_ - x;
    const double dy = y_ - y;
    return dx * dx + dy * dy <= radius_ * radius_;
  }

  private:
    const double x_;
    const double y_;
    const double radius_;
  };

  std::vector<int> SolveConeology(const int num_circle, Circle circles[]);
} // namespace pccb


