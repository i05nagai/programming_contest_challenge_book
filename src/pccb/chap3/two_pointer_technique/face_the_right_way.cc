#include "pccb/chap3/two_pointer_technique/face_the_right_way.h"
#include <algorithm>
#include <cassert>

namespace pccb {
  int calculate_num_operations(
      const int num_cow, const int num_seq, int dirs[])
  {
    int num_ops = 0;
    int sum_turn = 0;
    int turns[num_cow];
    std::fill(turns, turns + num_cow, 0);

    for (int i = 0; i <= num_cow - num_seq; ++i) {
      if ((sum_turn + dirs[i]) % 2 != 0) {
        turns[i] = 1;
        num_ops++;
      }
      sum_turn += turns[i];
      if (i - num_seq + 1 >= 0) {
        sum_turn -= turns[i - num_seq + 1];
      }
    }

    // check whther problem is solved
    for (int i = num_cow - num_seq + 1; i < num_cow; ++i) {
      if ((dirs[i] + sum_turn) % 2 != 0) {
        // no solution
        return -1;
      }
      if (i - num_seq + 1 >= 0) {
        sum_turn -= turns[i - num_seq + 1];
      }
    }
    return num_ops;
  }

  std::pair<int ,int> solve_face_the_right_way(
      const int num_cow, char directions[])
  {
    assert(1 <= num_cow);
    // conver to int arrays
    int dirs[num_cow];
    for (int i = 0; i < num_cow; ++i) {
      if (directions[i] == 'B') {
        dirs[i] = 1;
      } else {
        dirs[i] = 0;
      }
    }

    int num_sequence = 1;
    int num_operations = num_cow;
    for (int num_seq = 1; num_seq <= num_cow; ++num_seq) {
      // calc operations
      const int num_ops = calculate_num_operations(num_cow, num_seq, dirs);
      // solution is found and less than previous
      if (num_ops >= 0 && num_operations > num_ops) {
        num_operations = num_ops;
        num_sequence = num_seq;
      }
    }
    return std::pair<int, int>(num_operations, num_sequence);
  }
} // namespace pccb

