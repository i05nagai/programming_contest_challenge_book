#include "algorithm/segment_tree/range_minimum_query.h"
#include <algorithm>
#include <climits>

namespace pccb {
// tree[i]: parent
// tree[2 * i + 1]: left child of tree[i]
// tree[2 * i + 2]: right child of tree[i] 
inline int nodeIndexToLeftIndex(const int nodeIndex)
{
  return 2 * nodeIndex + 1;
}

inline int nodeIndexToRightIndex(const int nodeIndex)
{
  return 2 * nodeIndex + 2;
}

// allocate tree[size * 2 - 1]
int range_minimum_query_get_size(const int num_data)
{
  // find minimum power of 2 such that num_data < 2^{n}
  int size = 1;
  while (size < num_data) {
    size *= 2;
  }
  return size;
}

void range_minimum_query_init(int tree[], const int size)
{
  for (int i = 0; i < 2 * size - 1; ++i) {
    tree[i] = 1e8;
  }
}

void range_minimum_query_update(
    int tree[], const int size, const int index, int value)
{
  // leaf index
  int k = index + size - 1;
  tree[k] = value;
  // leaf to root node
  while (k > 0) {
    k = (k - 1) / 2;
    // 2 * k + 1 is previous k
    // 2 * k + 2 is parent segment
    tree[k] = std::min(tree[2 * k + 1], tree[2 * k + 2]);
  }
}

/**
 * @brief find the minimum value between [left, right)
 *
 * @param tree[]
 * @param size
 * @param left
 * @param right
 * @param rangeIndex
 * @param rangeLeftIndex represent interval of rangeIndex.
 * @param rangeRightIndex
 *
 * tree[rangeIndex] is the minimum value of [rangeLeftIndex, rangeRightIndex).
 * rangeIndex show the value for the range [rangeLeftIndex, rangeRightIndex).
 * The triple (rangeIndex, rangeLeftIndex, rangeRightIndex)
 * denotes one Range object for tree[].
 *
 * @return 
 */
int range_minimum_query_do_query(
    int tree[],
    const int left,
    const int right,
    const int rangeIndex,
    const int rangeLeftIndex,
    const int rangeRightIndex)
{
  // not crossed
  if (rangeRightIndex <= left || right <= rangeLeftIndex) {
    return INT_MAX;
  }

  // [left, right) contains [rangeLeftIndex, rangeRightIndex)
  if (left <= rangeLeftIndex && rangeRightIndex <= right) {
    return tree[rangeIndex];
  } else {
    const int value1 = range_minimum_query_do_query(
        tree,
        left,
        right,
        nodeIndexToLeftIndex(rangeIndex),
        left,
        (left + right) / 2);
    const int value2 = range_minimum_query_do_query(
        tree,
        left,
        right,
        nodeIndexToRightIndex(rangeIndex),
        (left + right) / 2,
        right);
    return std::min(value1, value2);
  }
}

// find the minimum value in all values
int range_minimum_query_query(
    int tree[],
    const int size)
{
  const int left = 0;
  const int right = size - 1;
  return range_minimum_query_do_query(tree, left, right, 0, 0, size);
}
} // namespace pccb
