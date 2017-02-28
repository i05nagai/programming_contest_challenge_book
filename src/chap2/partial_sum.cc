#include "chap2/partial_sum.h"
#include <algorithm>
#include <iterator>

bool partial_sum(
    const int length, const int items[], const int nums[], const int total)
{
  // memoRest[itemIndex][value]
  // number of itemIndex-th item to achive value adding items from 1st to itemIndex th
  int memoRest[length + 1][total + 1];
  memset(memoRest, -1, sizeof(memoRest));
  memoRest[0][0] = 0;

  for (std::size_t itemIndex = 0; itemIndex < length; ++itemIndex) {
    for (std::size_t value = 0; value <= total; ++value) {
      // value is achievable by itemIndex - th items
      if (memoRest[itemIndex][value] >= 0) {
          memoRest[itemIndex + 1][value] = items[itemIndex];
      // no item to add
      } else if (value < items[itemIndex] 
                 || memoRest[itemIndex][value - items[itemIndex]] <= 0) {
          memoRest[itemIndex + 1][value] = -1;
      // value is achievable by adding itemIndex-th item
      } else {
          memoRest[itemIndex + 1][value] 
            = memoRest[itemIndex][value - items[itemIndex]] - 1;
      }
    }
  }
  return memoRest[length][total] >= 0;
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

