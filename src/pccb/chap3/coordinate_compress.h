#pragma once

namespace pccb {
void coordinate_compress_draw_from_line(
    const int num_col,
    const int num_row,
    const int num_line,
    const int start_cols[],
    const int start_rows[],
    const int end_cols[],
    const int end_rows[]);
void coordinate_compress_draw(const int row, const int col, bool** table);

int coordinate_compress(
    const int numCols,
    const int numRows,
    const int numLines,
    int startCols[],
    int startRows[],
    int endCols[],
    int endRows[]);
} // namespace pccb
