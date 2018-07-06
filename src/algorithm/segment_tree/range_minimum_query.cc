#include "chap3/range_minimum_query.h"
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

int range_minimum_query_init(int tree[], const int size)
{
    // find minimum value(num) achieving size < 2^{num}
    int newSize = 1;
    while (newSize < size) {
        newSize *= 2;
    }

    for (int i = 0; i < 2 * newSize - 1; ++i) {
        tree[i] = INT_MAX;
    }

    return newSize;
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
 * @brief for recursive
 *
 * @param tree[]
 * @param size
 * @param left
 * @param right
 * @param nodeIndex
 * @param nodeStartIndex
 * @param nodeEndIndex
 *
 * @return 
 */
int range_minimum_query_do_query(
    int tree[],
    const int size,
    const int left,
    const int right,
    const int nodeIndex,
    const int nodeStartIndex,
    const int nodeEndIndex)
{
  // not crossed
  if (nodeStartIndex <= left || right <= nodeEndIndex) {
    return INT_MAX;
  }

  // [left, right) contains [nodeStartIndex, nodeEndIndex)
  if (left <= nodeStartIndex && nodeEndIndex <= right) {
    return tree[nodeIndex];
  } else {
    const int value1 = range_minimum_query_do_query(
        tree,
        size,
        left,
        right,
        2 * nodeIndex + 1,
        right,
        (left + right) / 2);
    const int value2 = range_minimum_query_do_query(
        tree,
        size,
        left,
        right,
        2 * nodeIndex + 2,
        (left + right) / 2,
        left);
    return std::min(value1, value2);
  }
}

int range_minimum_query_query(
    int tree[],
    const int size,
    const int left,
    const int right)
{
    return range_minimum_query_do_query(tree, size, left, right, 0, 0, size);
}
} // namespace pccb
