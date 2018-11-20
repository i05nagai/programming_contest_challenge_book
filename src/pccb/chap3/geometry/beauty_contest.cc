#include "pccb/chap3/geometry/beauty_contest.h"
#include <algorithm>

namespace pccb {

  double SolveBeautyContest(const std::vector<Point>& points)
  {
    std::vector<Point> convex_hull = ConvexHull(points);
    double distance = 0.0;
    for (int i = 0; i < convex_hull.size(); ++i) {
      for (int j = 0; j < convex_hull.size(); ++j) {
        distance = std::max(distance, Distance(convex_hull[i], convex_hull[j]));
      }
    }
    return distance * distance;
  }
} // namespace pccb




