#include "algorithm/segment_tree/solve_count_bubble_sort.h"
#include <cassert>
#include <cstring>
#include <iostream>

namespace pccb {
// Count the number of swap in bubble sort
// data is permutation of sequence from 1 to n
long long SolveCountBubbleSort(int data[], const int size)
{
  // tree[i]: num of swap between i and i + 1
  // summation from tree[1] to tree[j] is the number of i such that
  // i < j, data[i] <= data[j]
  // j - (summation from tree[1] to tree[i]) is the number of i such that
  // i < j, data[i] > data[j]
  int tree[size + 1];
  for (int i = 0; i <= size; ++i) {
    tree[i] = 0;
  }

  long long numSwaps = 0;
  for (int j = 0; j < size; ++j) {
    numSwaps += j - SumBinaryIndexTree(tree, data[j]);
    AddBinaryIndexTree(tree, size, data[j], 1);
  }
  return numSwaps;
}
} // namespace pccb
