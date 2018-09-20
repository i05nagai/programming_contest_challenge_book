#include "algorithm/bucket_method/range_minimum_query.h"
#include <algorithm>
#include <climits>
#include <cmath>

namespace pccb {
namespace bucket_method {
constexpr int INF = 1e9;

inline int GetBucketIndex(const int index, const int size_bucket) {
  return (index / size_bucket);
}

inline int GetFirstIndex(const int bucket_index, const int size_bucket) {
  return bucket_index * size_bucket;
}

int RangeMinimumQueryGetSize(const int size) {
  return std::floor(std::sqrt(size));
}

// size of bucket is given by RangeMinimumQueryGetSize
// initialize bucket with the minimum value
void RangeMinimumQueryInit(int data[], int size, int bucket[]) {
  // initialize
  const int size_bucket = RangeMinimumQueryGetSize(size);
  int counter = 0;
  int min_in_bucket = INF;
  for (int i = 0; i < size; ++i) {
    bucket[i] = data[i];
    min_in_bucket = std::min(min_in_bucket, data[i]);
    counter++;
    if (counter == size_bucket) {
      const int b_index = GetBucketIndex(i, size_bucket);
      bucket[b_index] = min_in_bucket;
      counter = 0;
    }
  }
}

void RangeMinimumQueryUpdate(
    int data[], int bucket, const int size, const int index, int value) {
  data[index] = value;
  const int b_index = GetBucketIndex(index, size);
  data[b_index] = std::min(data[b_index], value);
}

// find the minimum value in all values
int RangeMinimumQueryQuery(
    int data[],
    int bucket[],
    const int size,
    const int left,
    const int right)
{
  const int size_bucket = RangeMinimumQueryGetSize(size);
  int min = INF;
  int bucket_left = GetBucketIndex(left, size_bucket);
  int bucket_right = GetBucketIndex(left, size_bucket);
  if (left > GetFirstIndex(bucket_left, size_bucket)) {
    // check min from left to before next bucket
    bucket_left++;
    for (int i = left; i < GetFirstIndex(bucket_left, size_bucket); ++i) {
      min = std::min(data[i], min);
    }
  }
  if (right > GetFirstIndex(bucket_right, size_bucket)) {
    // check min from first index in bucket to right
    for (int i = GetFirstIndex(bucket_right, size_bucket); i <= right; ++i) {
      min = std::min(data[i], min);
    }
    bucket_right--;
  }
  // find min in bueckets
  for (int i = bucket_left; i <= bucket_right; ++i) {
    min = std::min(min, bucket[i]);
  }

  return min;
}
} // namespace bucket_method
} // namespace pccb
