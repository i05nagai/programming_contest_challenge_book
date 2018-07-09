#include "pccb/chap2/crazy_rows.h"

#include <iostream>

int crazy_rows(const std::vector<std::vector<int> >& matrix)
{
    // we assumes matrix can be transformed 
    // to (upper or lower) triangular matrix.
    const int numRow = matrix.size();
    const int numCol = matrix[0].size();
    
    // column position of last non-zero element for each rows
    int positionLastNonZero[numRow];
    
    // find last non zero element for each rows
    for (int row = 0; row < numRow; ++row) {
        // for the case of zero row
        positionLastNonZero[row] = -1;
        for (int col = numCol - 1; col >= 0; --col) {
            if (matrix[row][col] != 0) {
                positionLastNonZero[row] = col;
                break;
            }
        }
    }

    int numSwap = 0;
    for (int row = 0; row < numRow; ++row) {
        // row will be swaped
        int swapRow = -1;
        // find last 
        for (swapRow = row; swapRow < numRow; ++swapRow) {
            if (positionLastNonZero[swapRow] <= row) {
                break;
            }
        }
        //swap
        for (int r = swapRow; r > row; --r) {
            std::swap(positionLastNonZero[r], positionLastNonZero[r - 1]);
            ++numSwap;
        }
    }
    return numSwap;
}
