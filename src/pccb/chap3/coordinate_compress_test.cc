#include "pccb/chap3/coordinate_compress.h"
#include <gtest/gtest.h>

namespace pccb {
// examples are in p 151
TEST(coordinate_compress, simple)
{
    const int num_cols = 10;
    const int num_rows = 10;
    const int num_lines = 5;
    // Line1: (0, 3) -> (5, 3)
    int start_cols[] = {
        0, 0, 3, 8, 9,
    };
    int start_rows[] = {
        3, 7, 0, 0, 5,
    };
    int end_cols[] = {
        5, 9, 3, 8, 9,
    };
    int end_rows[] = {
        3, 7, 9, 4, 9,
    };
    // coordinate_compress_draw_from_line(
    //     num_cols,
    //     num_rows,
    //     num_lines,
    //     start_cols,
    //     start_rows,
    //     end_cols,
    //     end_rows);

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
} // namespace pccb
