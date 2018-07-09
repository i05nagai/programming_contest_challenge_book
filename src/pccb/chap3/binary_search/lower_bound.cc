#include "pccb/chap3/binary_search/lower_bound.h"
#include <iostream>

int find_lower_bound_index(const int n, int sequence[], const int lower_bound)
{
  int from = -1;
  int to = n;

  while (to - from > 1) {
    const int mid = int((to + from) * 0.5);
    if (sequence[mid] >= lower_bound){
      // (from, mid]
      to = mid;
    } else {
      // (mid, to] or (mid, n)
      from = mid;
    }
  }
  // (n-1, n)
  return to;
}
