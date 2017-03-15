#pragma once
#include <vector>


/**
 * @brief number of row swap to be lower-triangular matrix.
 *  row swap is only allowed next row.
 *  matrix should be transformed to lower-triangular matrix.
 *
 * @param matrix
 *
 * @return number of swap
 */
int crazy_rows(const std::vector<std::vector<int> >& matrix);

