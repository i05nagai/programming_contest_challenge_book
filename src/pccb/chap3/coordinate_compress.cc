#include "pccb/chap3/coordinate_compress.h"
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

namespace pccb {

// return length of compressed table
// start[]: coordinates of drawed lines. row/col but consistent with end[].
// end[]: coordinates of drawed lines. row/col
int compress(int start[], int end[], const int numLines, const int size) 
{
    std::vector<int> xs;

    for (int i = 0; i < numLines; ++i) {
      for (int d = -1; d <= 1; ++d) {
        int tx1 = start[i] + d;
        int tx2 = end[i] + d;
        if (1 <= tx1 && tx1 <= size) {
          xs.push_back(tx1);
        }
        if (1 <= tx2 && tx2 <= size) {
          xs.push_back(tx2);
        }
      }
    }

    // to delete duplicate elements
    std::sort(xs.begin(), xs.end());
    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());

    for (int i = 0; i < numLines; ++i) {
      start[i] = std::find(xs.begin(), xs.end(), start[i]) - xs.begin();
      end[i] = std::find(xs.begin(), xs.end(), end[i]) - xs.begin();
    }

    return xs.size();
}

// FIXME
int coordinate_compress(
    const int numCols,
    const int numRows,
    const int numLines,
    int startCols[],
    int startRows[],
    int endCols[],
    int endRows[])
{
    static const int dRows[] = {
        0, 0, 1, -1,
    };
    static const int dCols[] = {
        1, -1, 0, 0,
    };

    const int compressedNumCols = compress(startCols, endCols, numLines, numCols);
    const int compressedNumRows = compress(startRows, endRows, numLines, numRows);

    // fill the liens
    bool table[compressedNumRows][compressedNumCols];
    std::memset(table, 0, sizeof(table));
    // drow compressed lattice
    for (int i = 0; i < numLines; ++i) {
      for (int row = startRows[i]; row <= endRows[i]; ++row) {
        for (int col = startCols[i]; col <= endCols[i]; ++col) {
          table[row][col] = true;
        }
      }
    }

    int numRegions = 0;
    for (int row = 0; row < compressedNumRows; ++row) {
      for (int col = 0; col < compressedNumCols; ++col) {
        // if it is line or it has been already counted reagions
        if (table[row][col]) {
          continue;
        }
        ++numRegions;

        // lenght first search
        std::queue<std::pair<int, int>> queue;
        queue.push(std::make_pair(row, col));
        while (!queue.empty()) {
          const int startRow = queue.front().first;
          const int startCol = queue.front().second;
          queue.pop();

          // search each directions
          for (int i = 0; i < 4; ++i) {
            const int tempRow = startRow + dRows[i];
            const int tempCol = startCol + dCols[i];
            if (tempCol < 0 || numCols <= tempCol || tempRow < 0 || numRows <= tempRow) {
              continue;
            }
            // hit to boundary
            if (table[tempRow][tempCol]) {
              continue;
            }
            queue.push(std::make_pair(tempRow, tempCol));
            table[tempRow][tempCol] = true;
          }
        }
      }
    }

    return numRegions;
}
} // namespace pccb
