#include "algorithm/queue/window_minimum.h"
#include <deque>

namespace algorithm {
namespace queue {
  std::vector<int> SolveWindowMinimum(
      int sequence[],
      const int sequence_size,
      const int window_size)
  {
    std::deque<int> deq;
    std::vector<int> result;
    for (int i = 0; i < sequence_size; i++) {
      while (!deq.empty() && sequence[deq.back()] >= sequence[i]) {
        deq.pop_back();
      }
      deq.push_back(i);
      if (i - window_size + 1 >= 0) {
        result.push_back(sequence[deq.front()]);

        if (deq.front() == i - window_size + 1) {
          deq.pop_front();
        }
      }
    }

    return result;
  }
} // namespace queue
} // namespace algorithm
