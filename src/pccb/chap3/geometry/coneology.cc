#include "pccb/chap3/geometry/coneology.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>

namespace pccb {

  // container include a or not
  bool IsIncluded(const Circle& a, const Circle& container) {
    return container.Contain(a.X(), a.Y());
  }

  std::vector<int> SolveConeology(const int num_circle, Circle circles[])
  {
    // list of most dominant circle
    std::vector<int> results;

    // (x-axis, id)
    std::vector<std::pair<double, int>> events;
    for (int i = 0; i < num_circle; ++i) {
      const Circle& circle = circles[i];
      // leftmost
      events.push_back(std::make_pair(circle.X() - circle.Radius(), i));
      // rightmost
      events.push_back(std::make_pair(circle.X() + circle.Radius(), i + num_circle));
    }
    std::sort(events.begin(), events.end());

    // (x-axis, id)
    std::set<std::pair<double, int>> outers;

    for (int i = 0; i < events.size(); ++i) {
      const int c_id = events[i].second % num_circle;
      const Circle& circle = circles[c_id];
      // leftmost
      if (events[i].second < num_circle) {
        std::set<std::pair<double, int>>::iterator it = outers.lower_bound(std::make_pair(circle.Y(), c_id));
        if (it != outers.end() && IsIncluded(circle, circles[it->second])) {
          continue;
        }
        if (it != outers.begin() && IsIncluded(circle, circles[(--it)->second])) {
          continue;
        }
        results.push_back(c_id + 1);
        outers.insert(std::make_pair(circles[c_id].Y(), c_id));
      // rightmost
      } else {
        outers.erase(std::make_pair(circles[c_id].Y(), c_id));
      }
    }

    std::sort(results.begin(), results.end());
    return results;

  }
} // namespace pccb



