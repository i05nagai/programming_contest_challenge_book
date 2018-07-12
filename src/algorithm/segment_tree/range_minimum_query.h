#pragma once

namespace pccb {
  int range_minimum_query_get_size(const int num_data);
  /**
   * @brief 
   *
   * @param tree[] values from 0 to size - 1 are used for segment tree,
   *  values from size - 1 to 2*size - 1 has values of original sequence.
   *  tree[i] (i >= size - 1) are contained segment tree[(size
   *  tree[0] is root
   * @param size
   *
   * @return return new size of tree.
   *  size is adjusted to power of 2 for simplicity.
   */
  void range_minimum_query_init(int tree[], const int size);

  /**
   * @brief 
   *
   * @param tree[]
   * @param size
   * @param index
   * @param value
   */
  void range_minimum_query_update(
      int tree[], const int size, const int index, int value);
  /**
   * @brief wrapper of _query_range_minimum_query
   *
   * @param tree[]
   * @param size
   * @param left
   * @param right
   *
   * @return 
   */
  int range_minimum_query_query(
      int tree[],
      const int size);
} // namespace pccb
