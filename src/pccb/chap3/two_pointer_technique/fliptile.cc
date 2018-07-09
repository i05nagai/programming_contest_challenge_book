#include "pccb/chap3/two_pointer_technique/fliptile.h"
#include <algorithm>

namespace pccb {
  int get_fliptile_color(
      const int r,
      const int c,
      const int row,
      const int col,
      const int dr[],
      const int dc[],
      const std::vector<std::vector<int>>& tiles,
      std::vector<std::vector<int>>& flips) {
    int color = tiles[r][c];
    for (int d = 0; d < 5; d++) {
      const int r2 = r + dr[d];
      const int c2 = c + dc[d];
      if (0 <= r2 && r2 < row
          && 0 <= c2 && c2 < col) {
        color += flips[r2][c2];
      }
    }
    return color % 2;
  }

  int solve_fliptile_from_second_line(
      const int row,
      const int col,
      const std::vector<std::vector<int>>& tiles,
      std::vector<std::vector<int>>& flips)
  {
    const int dr[] = {
      -1, 0, 0, 0, 1,
    };
    const int dc[] = {
      0, -1, 0, 1, 0,
    };

    for (int r = 1; r < row; ++r) {
      for (int c = 0; c < col; ++c) {
        if (get_fliptile_color(r - 1, c, row, col, dr, dc, tiles, flips) != 0) {
          // If (r - 1, c) is black, we need to flip (r, c)
          flips[r][c] = 1;
        }
      }
    }

    // check the last line is all white
    for (int c = 0; c < col; ++c) {
      if (get_fliptile_color(row - 1, c, row, col, dr, dc, tiles, flips) != 0) {
        // no solution
        return -1;
      }
    }

    // number of flips
    int num_flips = 0;
    for (int r = 0; r < row; ++r) {
      for (int c = 0; c < col; ++c) {
        num_flips += flips[r][c];
      }
    }

    return num_flips;
  }

  std::pair<std::vector<std::vector<int>>, int> solve_fliptile(
      const int row,
      const int col,
      const std::vector<std::vector<int>>& tiles)
  {
    int num_flips = -1;
    // check flip or not
    std::vector<std::vector<int>> flips(row, std::vector<int>(col, 0));
    std::vector<std::vector<int>> ops(row, std::vector<int>(col, 0));

    // try possible flips for the fist line
    for (int i = 0; i < 1 << col; ++i) {
      // initalize flips
      for (int r = 0; r < row; ++r) {
        std::fill(flips[r].begin(), flips[r].end(), 0);
      }
      for (int c = 0; c < col; ++c) {
        flips[0][col - c - 1] = i >> c & 1;
      }
      const int num = solve_fliptile_from_second_line(
          row, col, tiles, flips);
      // solvable
      if (num >= 0 && (num_flips < 0 || num_flips > num)) {
        num_flips = num;
        ops = std::vector<std::vector<int>>(flips);
      }
    }

    return std::pair<std::vector<std::vector<int>>, int>(ops, num_flips);
  }
} // namespace pccb
