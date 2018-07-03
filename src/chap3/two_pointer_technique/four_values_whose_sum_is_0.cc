#include "chap3/two_pointer_technique/four_values_whose_sum_is_0.h"
#include <algorithm>
#include <iostream>

namespace pccb {
  int solve_four_values_whose_sum_is_0(
      const int num_elem,
      int list_a[],
      int list_b[],
      int list_c[],
      int list_d[])
  {
    const int num = num_elem * num_elem;
    int list_ab[num];
    int list_cd[num];
    for (int i = 0; i < num_elem; ++i) {
      for (int j = 0; j < num_elem; ++j) {
        list_ab[i * num_elem + j] = list_a[i] + list_b[j];
        list_cd[i * num_elem + j] = list_c[i] + list_d[j];
      }
    }

    std::sort(list_ab, list_ab + num);
    std::sort(list_cd, list_cd + num);

    // a + b = -(c + d)
    int counter = 0;
    for (int i = 0; i < num; ++i) {
      const int val = -list_ab[i];
      int low = 0;
      int high = num;
      while ((high - low) > 1) {
        const int mid = (high + low) / 2;
        if (list_cd[mid] == val) {
          counter++;
          break;
        } else if (list_cd[mid] > val) {
          high = mid;
        } else {
          low = mid;
        }
      }
    }
    return counter;
  }
} // namespace pccb
