#include "chap2/longest_common_subsequence.h"
#include <algorithm>

int longest_common_subsequence_dynamic_programming(
    const int length1, const char str1[],
    const int length2, const char str2[])
{
    // length of longest common sequence at (pos1, pos2)
    int memo[length1 + 1][length2 + 1];
    memset(memo, 0, sizeof(memo));

    for (int pos1 = 0; pos1 < length1; ++pos1) {
        for (int pos2 = 0; pos2 < length2; ++pos2) {
            // has same char
            if (str1[pos1] == str2[pos2]) {
                // need to forward both positions
                // and add length
                memo[pos1 + 1][pos2 + 1] = memo[pos1][pos2] + 1;
            } else {
                // we have 2 options
                // * forward str1 position
                // * forward str2 position
                memo[pos1 + 1][pos2 + 1] = std::max(
                    memo[pos1][pos2 + 1], memo[pos1 + 1][pos2]);
            }
        }
    }

    return memo[length1][length2];
}

