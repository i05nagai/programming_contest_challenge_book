#include "chap3/binary_search/cable_master.h"
#include <cassert>
#include <cmath>
#include <iostream>

namespace pccb {
  double solve_cable_master(
      const int num_cable,
      const int num_sub_cable,
      double length[]) {
    assert(num_cable >= 1);
    assert(num_sub_cable >= 1);
    //[0, min(Li))
    // get min
    double ub = length[0];
    double lb = 0.0;
    for (int i = 1; i < num_cable; ++i) {
      ub = std::min(ub, length[i]);
    }

    double previous_size = -1.0;
    double size = (ub + lb) / 2.0;
    while (std::abs(size - previous_size) > 1e-3) {
      // check that divide cables into num_sub_cable sub-cables
      int c = 0;
      for (int i = 0; i < num_cable; ++i) {
        c += int(length[i] / size);
      }
      if (c >= num_sub_cable) {
        // [size, ub)
        lb = size;
      } else {
        // [lb, size)
        ub = size;
      }
      previous_size = size;
      size = (ub + lb) / 2.0;
    }
    return lb;
  }
} // namespace pccb
