#include "pccb/chap2/knapsack.h"
#include <algorithm>
#define MAX_NUM_ITEM 100

int knapsack_simple(
    const int numItem,
    const int weights[],
    const int values[],
    int posItem,
    int remainingWeight)
{
    // reach last item
    if (posItem == numItem) {
        return 0;
    // overweight so skip this item
    } else if (remainingWeight - weights[posItem] < 0) {
        return knapsack_simple(
            numItem, weights, values, posItem + 1, remainingWeight);
    } else {
        // skip this item
        const int case_not_add = knapsack_simple(
            numItem, weights, values, 
            posItem + 1, remainingWeight);
        // add this item
        const int case_add = knapsack_simple(
            numItem, weights, values,
            posItem + 1, remainingWeight - weights[posItem])
            + values[posItem];
        return std::max(case_add, case_not_add);
    }
}

int do_knapsack_memoization(
    const int numItem,
    const int weights[],
    const int values[],
    int memoValues[][MAX_NUM_ITEM + 1],
    int posItem,
    int remainingWeight)
{
    // already calculated
    if (memoValues[remainingWeight][posItem] != -1) {
        return memoValues[remainingWeight][posItem];
    }

    int returnValue = 0;
    // reach last item
    if (posItem == numItem) {
        returnValue = 0;
    // overweight so skip this item
    } else if (remainingWeight - weights[posItem] < 0) {
        returnValue = do_knapsack_memoization(
                numItem, weights, values,
                memoValues, posItem + 1, remainingWeight);
    } else {
        // skip this item
        const int case_not_add = do_knapsack_memoization(
            numItem, weights, values,
            memoValues, posItem + 1, remainingWeight);
        // add this item
        const int case_add = do_knapsack_memoization(
            numItem, weights, values,
            memoValues, posItem + 1, remainingWeight - weights[posItem])
            + values[posItem];
        returnValue = std::max(case_add, case_not_add);
    }
    // memoize
    memoValues[remainingWeight][posItem] = returnValue;
    return returnValue;
}

int knapsack_memoization(
    const int numItem,
    const int weights[],
    const int values[],
    int posItem,
    int remainingWeight)
{
    int memoValues[remainingWeight + 1][MAX_NUM_ITEM + 1];
    // set uncalculated flag
    memset(memoValues, -1, sizeof(memoValues));
    return do_knapsack_memoization(
        numItem, weights, values, memoValues, posItem, remainingWeight);
}

int knapsack_dynamic_programming(
    const int numItem,
    const int weights[],
    const int values[],
    int posItem,
    int remainingWeight)
{
    int memoValues[remainingWeight + 1][MAX_NUM_ITEM + 1];
    // initliaze
    memset(memoValues, 0, sizeof(memoValues));
    // maxWeigth

    for (int posItem = numItem - 1; posItem >= 0; --posItem) {
        for (int weight = 0; weight <= remainingWeight; ++weight) {
            // overweigth so skip this item
            if (weight < weights[posItem]) {
                memoValues[weight][posItem] = memoValues[weight][posItem + 1];
            } else {
                memoValues[weight][posItem]
                    = std::max(
                        // do not add
                        memoValues[weight][posItem + 1],
                        // add
                        memoValues[weight - weights[posItem]][posItem + 1]
                        + values[posItem]);
            }
        }
    }

    return memoValues[remainingWeight][0];
}
