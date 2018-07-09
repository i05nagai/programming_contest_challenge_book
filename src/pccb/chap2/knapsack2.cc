#include "pccb/chap2/knapsack2.h"
#include <algorithm>
#include <iostream>

/**
 * @brief 
 *
 * @param numItem n
 * @param weights[] wi
 * @param values[] vi
 * @param maxWeight W
 *
 * @return 
 */
int knapsack2(
    const int numItem,
    const int weights[],
    const int values[],
    int maxWeight)
{
    constexpr int INF = 10000000;
    //find max values
    int maxValue = 0;
    for (int posItem = 0; posItem < numItem; ++posItem) {
        if (maxValue < values[posItem]) {
            maxValue = values[posItem];
        }
    }

    // memoWeights[i][j] minimum weight at value j using up to (i - 1)-th item
    int memoWeights[numItem + 1][numItem * maxValue + 1];
    memoWeights[0][0] = 0;
    for (int value = 1; value <= numItem * maxValue; ++value) {
      memoWeights[0][value] = INF;
    }

    // find item to equal total value of items to j
    // * by i-1 th item, value of items reaches j - v[i] and choose i th item
    // * value of items has already reached in i-1 th selection.
    for (int posItem = 0; posItem < numItem; ++posItem) {
        for (int value = 0; value <= numItem * maxValue; ++value) {
            //
            if (value < values[posItem]) {
                memoWeights[posItem + 1][value] = memoWeights[posItem][value];
            } else {
                memoWeights[posItem + 1][value] = std::min(
                    memoWeights[posItem][value],
                    memoWeights[posItem][value - values[posItem]]
                        + weights[posItem]);
            }
        }
    }
    
    // find maxValue
    int valueKnapsack = 0;
    for (int value = 0; value <= numItem * maxValue; ++value) {
        if (memoWeights[numItem][value] <= maxWeight) {
            valueKnapsack = value;
        }
    }
    return valueKnapsack;
}
