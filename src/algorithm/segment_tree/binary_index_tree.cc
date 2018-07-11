#include "algorithm/segment_tree/binary_index_tree.h"
#include <cstring>
#include <iostream>

namespace pccb {
int SumBinaryIndexTree(int tree[], int index)
{
  int sum = 0;
  while (index > 0) {
    sum += tree[index];
    index -= index & (-index);
  }
  return sum;
}
/**
 * @brief 
 *
 * @param tree[] size + 1
 * @param size
 * @param index
 * @param value
 */
void AddBinaryIndexTree(
    int tree[], const int size, int index, const int value)
{
  while (index <= size) {
    tree[index] += value;
    index += index & (-index);
  }
}
/**
 * @brief 
 *
 * @param tree[] size + 1
 * @param data[]
 * @param size
 */
void InitBinaryIndexTree(int tree[], int data[], const int size)
{
  for (int i = 1; i <= size; ++i) {
    tree[i] = data[i];
  }
}

// num of swap
// data is permutation of sequence from 1 to n
long long int SolveCountBubbleSort(int data[], const int size)
{
    // num of swaps
    // tree[i] detenos num of swap between i and i + 1
    int tree[size + 1];
    for (int i = 1; i <= size; ++i) {
        tree[i] = i;
    } 

    long long int numSwaps = 0;
    for (int j = 0; j < size; ++j) {
        numSwaps += j - SumBinaryIndexTree(tree, data[j]);
        AddBinaryIndexTree(tree, size, data[j], 1);
    }
    return numSwaps;
}
} // namespace pccb
