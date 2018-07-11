#include "pccb/chap3/two_pointer_technique/physics_experiment.h"
#include <algorithm>
#include <cmath>

namespace pccb {
  double calculate_height(
      const int height,
      const int time)
  {
    constexpr double g = 10.0;
    if (time < 0) {
      return height;
    }
    const double t = std::sqrt(2.0 * height / g);
    const int k = (int)(time / t);
    if (k % 2 == 0) {
      const double d = time - k * t;
      return height - g * d * d / 2.0;
    } else {
      const double d = k * t + t - time;
      return height - g * d *d / 2.0;
    }
  }

  std::vector<double> solve_physics_experiment(
      const int num_ball,
      const int radius,
      const int height,
      const int time)
  {
    std::vector<double> heights(num_ball);
    for (int i = 0; i < num_ball; i++) {
      heights[i] = calculate_height(height, time - i);
    }
    std::sort(heights.begin(), heights.end(), [](double a, double b) {
      // acending
      return a < b;
    });
    // adjust radius
    for (int i = 0; i < num_ball; ++i) {
      heights[i] += 2.0 * radius * i / 100.0;
    }
    return heights;
  }
} // namespace pccb
