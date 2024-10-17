#pragma once

namespace pccb {
int coordinate_compress(
    const int numCols,
    const int numRows,
    const int numLines,
    int startCols[],
    int startRows[],
    int endCols[],
    int endRows[]);
} // namespace pccb
