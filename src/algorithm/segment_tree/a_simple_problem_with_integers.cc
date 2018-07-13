#include "algorithm/segment_tree/a_simple_problem_with_integers.h"
#include <cassert>
#include <cstring>
#include <iostream>

namespace pccb {
inline int NodeLeft(const int index) {
  return 2 * index + 1;
}

inline int NodeRight(const int index) {
  return 2 * index + 2;
}

class Node {
public:
  int Val;
  int ValRange;
};

class Range {
public:
  Range(const int index, const int left, const int right)
  : Index(index),
    Left(left),
    Right(right)
  {
  }
  int Index;
  int Left;
  int Right;
  Range GetLeftHalf() const {
    return Range(
        NodeLeft(Index),
        Left,
        (Left + Right) / 2);
  }
  Range GetRightHalf() const {
    return Range(
        NodeRight(Index),
        (Left + Right) / 2,
        Right);
  }
  bool IsIntersect(const int left, const int right) const {
    // negate of not intersect
    return !(this->Right <= left || right <= this->Left);
  }
  bool IsIn(const int left, const int right) const {
    return left <= Left && Right <= right;
  }
};


// Add val to element between [left, right)
// index starts from 0 to size - 1
// [0, size) is range of tree[0]
void Add(
    Node tree[],
    const int left,
    const int right,
    const int val,
    const Range range) {
  if (range.IsIn(left, right)) {
    tree[range.Index].ValRange += val;
  } else if (range.IsIntersect(left, right)) {
    // intersect and length
    const int left_max = std::max(left, range.Left);
    const int right_min = std::min(right, range.Right);
    tree[range.Index].Val += (right_min - left_max) * val;
    Add(tree, left, right, val, range.GetLeftHalf());
    Add(tree, left, right, val, range.GetRightHalf());
  }
}

// Calculate summation of [left, right)
// index starts from 0 to size - 1
// [0, size) is range of tree[0]
long long Sum(
    Node tree[],
    const int left,
    const int right,
    const int range_index,
    const int range_left_index,
    const int range_right_index) {
  // out of range
  if (right <= range_left_index || range_right_index <= left) {
    // return nothing effects to sum
    return 0LL;
  } else if (left <= range_left_index && range_right_index <= right) {
    // if it is in
    return (tree[range_index].ValRange * (range_right_index - range_left_index)
            + tree[range_index].Val);
  } else {
    // if intersect
    const int left_max = std::max(left, range_left_index);
    const int right_min = std::min(right, range_right_index);
    // value added by Command query
    long long sum = (right_min - left_max) * tree[range_index].ValRange;
    const int range_mid_index = (range_left_index + range_right_index) / 2;
    sum += Sum(tree, left, right, NodeLeft(range_index), range_left_index, range_mid_index);
    sum += Sum(tree, left, right, NodeRight(range_index), range_mid_index, range_right_index);
    return sum;
  }
}

  std::vector<long long> SolveASimpleProblemWithIntegers(
    int data[],
    const int size,
    const std::vector<SolveASimpleProblemWithIntegersQuery>& query)
{
  // initialize
  Node tree[2 * size + 2];
  for (int i = 0; i < 2 * size + 2; ++i) {
    tree[i] = Node();
  }
  // set values
  for (int i = 0; i < size; ++i) {
    Add(tree, i, i + 1, data[i], Range(0, 0, size));
  }

  std::vector<long long> answers(0);
  for (int i = 0; i < query.size(); ++i) {
    const SolveASimpleProblemWithIntegersQuery& q = query[i];
    if (q.Type == 'C') {
      // add x from a[l] to [r]
      const int left = q.Data[0] - 1;
      const int right = q.Data[1];
      const int x = q.Data[2];
      Add(tree, left, right, x, Range(0, 0, size));
    } else {
      // sum from a[l] to [r]
      const int left = q.Data[0] - 1;
      const int right = q.Data[1];
      const long long s = Sum(tree, left, right, 0, 0, size);
      answers.push_back(s);
    }
  }

  return answers;
}

/*--------------------------------------------------------------------------
* BIT
*------------------------------------------------------------------------*/

long long SumWithBIT(long long b[], int index) {
  long long s = 0;
  while (index > 0) {
    s += b[index];
    index -= index & -index;
  }
  return s;
}

void AddWithBIT(
    long long b[], const int size, int i, int val) {
  while(i <= size) {
    b[i] += val;
    i += i & (-i);
  }
}
  std::vector<long long> SolveASimpleProblemWithIntegersWithBIT(
    int data[],
    const int size,
    const std::vector<SolveASimpleProblemWithIntegersQuery>& query)
{
  // initialize
  long long bit0[2 * size + 1];
  long long bit1[2 * size + 1];
  for (int i = 0; i < 2 * size + 1; ++i) {
    bit0[i] = 0LL;
    bit1[i] = 0LL;
  }
  for (int i = 1; i <= size; ++i) {
    AddWithBIT(bit0, size, i, data[i - 1]);
  }

  std::vector<long long> answers(0);
  for (int i = 0; i < query.size(); ++i) {
    const SolveASimpleProblemWithIntegersQuery& q = query[i];
    if (q.Type == 'C') {
      // add x from a[l] to a[r]
      const int left = q.Data[0];
      const int right = q.Data[1];
      const int x = q.Data[2];
      // sum(bit1, i) * i + sum(bit0, i)
      AddWithBIT(bit0, size, left, -x * (left - 1));
      AddWithBIT(bit1, size, left, x);
      AddWithBIT(bit0, size, right + 1, x * right);
      AddWithBIT(bit1, size, right + 1, -x);
    } else {
      // sum from a[l] to a[r]
      const int left = q.Data[0];
      const int right = q.Data[1];
      long long s = SumWithBIT(bit0, right) + SumWithBIT(bit1, right) * right;
      s -= SumWithBIT(bit0, left - 1) + SumWithBIT(bit1, left - 1) * (left - 1);
      answers.push_back(s);
    }
  }

  return answers;
}
} // namespace pccb

