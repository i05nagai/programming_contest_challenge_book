#include "algorithm/segment_tree/binary_index_tree.h"
#include <cassert>
#include <cstring>
#include <iostream>

namespace pccb {
int SumBinaryIndexTree(int tree[], int index)
{
  // from index to size
  assert(1 <= index);
  int sum = 0;
  while (index > 0) {
    sum += tree[index];
    // subtract (first non-zero bit)
    index -= index & (-index);
  }
  return sum;
}

void AddBinaryIndexTree(
    int tree[], const int size, int index, const int value)
{
  while (index <= size) {
    tree[index] += value;
    // add (first non-zero bit)
    index += index & (-index);
  }
}

void InitBinaryIndexTree(int tree[], int data[], const int size)
{
  for (int i = 0; i <= size; ++i) {
    tree[i] = 0;
  }
  for (int i = 1; i <= size; ++i) {
    AddBinaryIndexTree(tree, size, i, data[i-1]);
  }
}
} // namespace pccb
