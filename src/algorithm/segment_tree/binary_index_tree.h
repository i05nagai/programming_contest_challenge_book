#pragma once

namespace pccb {
  /**
   * @brief get sum from data[0] to data[index],
   *
   * @param tree[]
   * @param index
   *
   * @return 
   */
int SumBinaryIndexTree(int tree[], int index);
/**
 * @brief 
 *
 * @param tree[] must be size + 1
 * @param size
 * @param index
 * @param value
 */
void AddBinaryIndexTree(
    int tree[], const int size, int index, const int value);
/**
 * @brief Initialize binary index tree with data[].
 *
 * @param tree[] size + 1
 * @param data[] size
 * @param size size of data
 */
void InitBinaryIndexTree(int tree[], int data[], const int size);
} // namespace pccb
