#pragma once
#include <utility>
#include <vector>

namespace pccb {
  // x, y
  typedef std::pair<double, double> Point;

  class Box {
  public:
    // left lower and upper right
    Box(const Point ll, const Point ru)
      : ll_(ll), ru_(ru)
    {
    }

    const double& LeftLowerX() const {
      return ll_.first;
    }

    const double& LeftLowerY() const {
      return ll_.second;
    }

    const double& LeftUpperX() const {
      return ll_.first;
    }

    const double& LeftUpperY() const {
      return ru_.second;
    }

    const double& RightUpperX() const {
      return ru_.first;
    }

    const double& RightUpperY() const {
      return ru_.second;
    }

    const double& RightLowerX() const {
      return ru_.first;
    }

    const double& RightLowerY() const {
      return ll_.second;
    }

    const double& Left() const {
      return ll_.first;
    }

    const double& Right() const {
      return ru_.first;
    }

    const double& Lower() const {
      return ll_.second;
    }

    const double& Upper() const {
      return ru_.second;
    }

  private:
    Point ll_;
    Point ru_;
  };

  bool SolveWhiteBird(
      const int num_box,
      const double velocity,
      Box boxes[],
      const Point& pig);
} // namespace pccb
