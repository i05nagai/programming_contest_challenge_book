#include "pccb/chap3/binary_search/maximize_average.h"
#include <algorithm>
#include <functional>
#include <iostream>

namespace pccb {
  bool IsChoosable(
      const double value_per_weight,
      const int num_choice,
      const std::vector<MaximizeAverageItem>& items) {
    int num_item = items.size();
    double temp[num_item];
    for (int i = 0; i < num_item; ++i) {
      const MaximizeAverageItem& item = items[i];
      temp[i] = item.value - value_per_weight * item.value;
      std::cout << "temp[i]: " << temp[i] << std::endl;
    }
    std::cout << std::endl;
    std::sort(temp, temp + num_item, std::greater<double>());

    double sum = 0.0;
    for (int i = 0; i < num_choice; ++i) {
      sum += temp[i];
    }
    return sum >= 0.0;
  }

  double FindMaximumValuePerWeight(
      const std::vector<MaximizeAverageItem>& items) {
    const int num_item = items.size();
    if (num_item == 0) {
      return 0.0;
    }
    double maximum = items[0].value / items[0].weight;
    for (int i = 0; i < num_item; ++i) {
      const double v = items[i].value / (double) items[i].weight;
      maximum = std::max(maximum, v);
    }
    return maximum;
  }

  double SolveMaximizeAverage(
      const int num_choice,
      const std::vector<MaximizeAverageItem>& items)
  {
    assert(num_choice < items.size());

    double lb = 0.0;
    double ub = FindMaximumValuePerWeight(items);
    while (ub - lb > 1e-3) {
      const double mid = (ub + lb) / 2.0;
      std::cout << "ub: " << ub << std::endl;
      std::cout << "lb: " << lb << std::endl;
      std::cout << std::endl;
      if (IsChoosable(mid, num_choice, items)) {
        lb = mid;
      } else {
        ub = mid;
      }
    }
    // when while loop finishes after updating lb, lb satisfies the condition
    // when while loop finishes after updating ub, ub and lb satisfy the condition
    return lb;
  }
} // namespace pccb
