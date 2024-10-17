#include "pccb/chap3/coordinate_compress.h"
#include <gtest/gtest.h>

namespace pccb {
// examples are in p 151
TEST(coordinate_compress, simple)
{
  {
    const int num_cols = 10;
    const int num_rows = 10;
    const int num_lines = 5;
    // (row, col)
    // Line1: (4, 1) -> (4, 6)
    int start_rows[] = {
        4, 8, 1, 1, 6,
    };
    int start_cols[] = {
        1, 1, 4, 9, 10,
    };
    int end_rows[] = {
        4, 8, 10, 5, 10,
    };
    int end_cols[] = {
        6, 10, 4, 9, 10,
    };

    const int numRegions = coordinate_compress(
        num_cols,
        num_rows,
        num_lines,
        start_cols,
        start_rows,
        end_cols,
        end_rows);
    EXPECT_EQ(6, numRegions);
  }

  {
    const int num_cols = 10;
    const int num_rows = 10;
    const int num_lines = 5;
    // (row, col)
    // Line1: (4, 1) -> (4, 6)
    int start_rows[] = {
        4, 8, 1, 1, 6,
    };
    int start_cols[] = {
        1, 1, 4, 9, 10,
    };
    int end_rows[] = {
        4, 8, 10, 5, 10,
    };
    int end_cols[] = {
        5, 10, 4, 9, 10,
    };

    const int numRegions = coordinate_compress(
        num_cols,
        num_rows,
        num_lines,
        start_cols,
        start_rows,
        end_cols,
        end_rows);
    EXPECT_EQ(6, numRegions);
  }
}
} // namespace pccb
