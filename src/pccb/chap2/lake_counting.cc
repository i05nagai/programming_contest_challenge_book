#include "pccb/chap2/lake_counting.h"
#include <iterator>

void lake_counting_depth_first_search(
    char W[100][100], int numRow, int numCol, int row, int col)
{
    W[row][col] = '.';

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            const int nextRow = row + i;
            const int nextCol = col + j;

            //is in range?
            //and is lake?
            if ((nextRow < numRow && nextRow >= 0)
                && (nextCol < numCol && nextCol >= 0)
                && W[nextRow][nextCol] == 'W')
            {
                lake_counting_depth_first_search(
                    W, numRow, numCol, nextRow, nextCol);
            }
        }
    }
}

int lake_counting(char W[100][100], int numRow, int numCol)
{
    int numLake = 0;
    for (std::size_t row = 0; row < numRow; ++row) {
        for (std::size_t col = 0; col < numCol; ++col) {
            // is lake
            if (W[row][col] == 'W') {
                lake_counting_depth_first_search(W, numRow, numCol, row, col);
                ++numLake;
            }
        }
    }
    return numLake;
}

