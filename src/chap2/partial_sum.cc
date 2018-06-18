#include "chap2/partial_sum.h"
#include <algorithm>
#include <iterator>
#include <iostream>

// n: length
// ai: items
// mi: nums
// K: total
bool partial_sum(
    const int length, const int items[], const int nums[], const int total)
{
  // memoRest[itemIndex][value]
  // number of itemIndex-th item to achieve value adding items from 1st to itemIndex th
  bool memoRest[length + 1][total + 1];

  for (std::size_t itemIndex = 0; itemIndex < length; ++itemIndex) {
    for (std::size_t value = 0; value <= total; ++value) {
      memoRest[itemIndex][value] = false;
    }
  }
  memoRest[0][0] = true;

  for (std::size_t itemIndex = 0; itemIndex < length; ++itemIndex) {
    for (std::size_t value = 0; value <= total; ++value) {
      for (std::size_t k = 0; k <= nums[itemIndex] && k * items[itemIndex] <= value; ++k) {
        memoRest[itemIndex + 1][value] |= memoRest[itemIndex][value - k * items[itemIndex]];
      }
    }
  }
  return memoRest[length][total];
}

bool partial_sum_save_memory(
    const int length, const int items[], const int nums[], const int total)
{
  // memoRest[itemIndex][value]
  // number of itemIndex-th item to achive value adding items from 1st to itemIndex th
  int memoRest[total + 1];
  memset(memoRest, -1, sizeof(memoRest));
  memoRest[0] = 0;

  for (std::size_t itemIndex = 0; itemIndex < length; ++itemIndex) {
    for (std::size_t value = 0; value <= total; ++value) {
      // 
      if (memoRest[value] >= 0) {
          memoRest[value] = items[itemIndex];
      // no item to add
      } else if (value < items[itemIndex] 
         || memoRest[value - items[itemIndex]] <= 0) {
          memoRest[value] = -1;
      // value is achievable by adding itemIndex-th item
      } else {
          memoRest[value] = memoRest[value - items[itemIndex]] - 1;
      }
    }
  }
  return memoRest[total] >= 0;
}

