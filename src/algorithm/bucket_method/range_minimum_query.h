#pragma once

namespace pccb {
namespace bucket_method {
  int RangeMinimumQueryGetSize(const int size);
  void RangeMinimumQueryInit(int data[], int size, int bucket[]);
  /**
   * @brief 
   *
   * @param tree[]
   * @param size
   * @param index
   * @param value
   */
  void RangeMinimumQueryUpdate(
      int data[], const int size, const int index, int value);
  /**
   * @brief 
   *
   * @param data[]
   * @param size
   * @param left
   * @param right
   *
   * @return 
   */
  int RangeMinimumQueryQuery(
    int data[],
    int bucket[],
    const int size,
    const int left,
    const int right);
} // namespace bucket_method
} // namespace pccb
