#include "chap3/coordinate_compress.h"
#include <algorithm>
#include <queue>
#include <iostream>

namespace pccb {
void coordinate_compress_draw_from_line(
    const int num_col,
    const int num_row,
    const int num_line,
    const int start_cols[],
    const int start_rows[],
    const int end_cols[],
    const int end_rows[]) {
  bool** table = (bool**)malloc(num_row * sizeof(bool *));
  for (int r = 0; r < num_row; ++r) {
    table[r] = (bool*)malloc(num_col * sizeof(bool));
    for (int c = 0; c < num_col; ++c) {
      table[r][c] = false;
    }
  }
  for (int i = 0; i < num_line; ++i) {
    for (int row = start_rows[i]; row <= end_rows[i]; ++row) {
      for (int col = start_cols[i]; col <= end_cols[i]; ++col) {
        table[row][col] = true;
      }
    }
  }
  coordinate_compress_draw(num_row, num_col, (bool**)table);
  for (int r = 0; r < num_row; ++r) {
    free(table[r]);
  }
  free(table);
}

void coordinate_compress_draw(const int row, const int col, bool** table) {
  for (int r = 0; r < row; ++r) {
    for (int c = 0; c < col; ++c) {
      std::cout << table[r][c] << " ";
    }
    std::cout << std::endl;
  }
}

// return length of compressed table
// start[]: coordinates of drawed lines. row/col but consistent with end[].
// end[]: coordinates of drawed lines. row/col
int compress(int start[], int end[], const int numLines, const int size) 
{
    std::vector<int> xs;

    for (int i = 0; i < numLines; ++i) {
      for (int d = -1; d <= 1; ++d) {
        int tempStart = start[i] + d;
        int tempEnd = end[i] + d;
        // if in lattice
        if (0 <= tempStart && tempStart < size) {
          xs.push_back(tempStart);
        }
        if (0 < tempEnd && tempEnd < size) {
          xs.push_back(tempEnd);
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
    memset(table, 0, sizeof(table));
    // drow compressed lattice
    for (int i = 0; i < numLines; ++i) {
      for (int row = startRows[i]; row <= endRows[i]; ++row) {
        for (int col = startCols[i]; col <= endCols[i]; ++col) {
          table[row][col] = true;
        }
      }
    }
    // for (int r = 0; r < compressedNumRows; ++r) {
    //   for (int c = 0; c < compressedNumCols; ++c) {
    //     std::cout << table[r][c] << " ";
    //   }
    //   std::cout << std::endl;
    // }

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
        while (!queue.empty()) {
          const int startRow = queue.front().first;
          const int startCol = queue.front().second;
          queue.pop();

          // search each directions
          for (int i = 0; i < 4; ++i) {
            const int tempRow = startRow + dRows[i];
            const int tempCol = startCol + dCols[i];
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
