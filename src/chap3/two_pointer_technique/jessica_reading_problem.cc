#include "chap3/two_pointer_technique/jessica_reading_problem.h"
#include <algorithm>
#include <set>

namespace pccb {
  int solve_jessica_reading_problem(const int num_page, int ids[])
  {
    typedef std::set<int> ID;
    ID id_set;
    for (int i = 0; i < num_page; ++i) {
      id_set.insert(ids[i]);
    }

    int from = 0;
    int to = 0;
    int page = num_page + 1;

    while (true) {
      std::set<int> copy = id_set;
      while (to < num_page && copy.size() > 0) {
        copy.erase(ids[to++]);
      }
      
      // to == num_page
      if (copy.size() > 0) {
        break;
      }
      page = std::min(page, to - from);
      from++;
    }

    // this never happen
    if (page > num_page) {
      return 0;
    }
    return page;
  }
} // namespace pccb
