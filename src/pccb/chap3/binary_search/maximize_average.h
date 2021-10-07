#pragma once
#include <vector>

namespace pccb {
  struct MaximizeAverageItem {
    MaximizeAverageItem(const int w, const int v)
      :weight(w), value(v) {};
    int weight;
    int value;
  };
  double SolveMaximizeAverage(
      const int num_choice,
      const std::vector<MaximizeAverageItem>& items);
} // namespace pccb
