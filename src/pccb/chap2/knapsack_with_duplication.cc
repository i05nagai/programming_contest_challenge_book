#include "pccb/chap2/knapsack_with_duplication.h"
#include <algorithm>
#include <cstring>

int knapsack_with_duplication(
    const int numItem,
    const int weights[],
    const int values[],
    const int maxWeight)
{
    // memoValues[i][j] denotes that
    // the maximum value of the knapsack 
    // when knapsack has enough space 
    // to put in the items between 0th and i - 1 th
    int memoValues[numItem + 1][maxWeight + 1];
    std::memset(memoValues, 0, sizeof(memoValues));

    for (int posItem = 0; posItem < numItem; ++posItem) {
       for (int weight = 0; weight <= maxWeight; ++weight) {
           // take
           // max{memoValues[posItem][weight - k * weights[posItem]] 
           // + k * values[posItem] | k <= 0}
           // and substitute it to memoValues[posItem + 1][weight]
           for (int k = 0; k * weights[posItem] <= weight; ++k) {
             memoValues[posItem + 1][weight] = std::max(
                 memoValues[posItem + 1][weight],
                 memoValues[posItem][weight - k * weights[posItem]] 
                     + k * values[posItem]);
           }
       }
    }

    return memoValues[numItem][maxWeight];
}

int knapsack_with_duplication_simple(
    const int numItem,
    const int weights[],
    const int values[],
    const int maxWeight)
{
    // memoValues[i][j] denotes that
    // the maximum value of the knapsack 
    // when knapsack has enough space 
    // to put in the items between 0th and i - 1 th
    int memoValues[numItem + 1][maxWeight + 1];
    std::memset(memoValues, 0, sizeof(memoValues));

    for (int posItem = 0; posItem < numItem; ++posItem) {
       for (int weight = 0; weight <= maxWeight; ++weight) {
           // take
           // max{memoValues[posItem][weight - k * weights[posItem]] 
           // + k * values[posItem] | k <= 0}
           int maxValue = 0.0;
           for (int k = 0; k * weights[posItem] <= weight; ++k) {
              maxValue = std::max(
                 maxValue,
                 memoValues[posItem][weight - k * weights[posItem]] 
                     + k * values[posItem]);
           }
           // substitute it to memoValues[posItem][weight]
           memoValues[posItem + 1][weight] = maxValue;
       }
    }

    return memoValues[numItem][maxWeight];
}

int knapsack_with_duplication_fast(
    const int numItem,
    const int weights[],
    const int values[],
    const int maxWeight)
{
    // memoValues[i][j] denotes that
    // the maximum value of the knapsack 
    // when knapsack has enough space 
    // to put in the items between 0th and i - 1 th
    int memoValues[numItem + 1][maxWeight + 1];
    std::memset(memoValues, 0, sizeof(memoValues));

    for (int posItem = 0; posItem < numItem; ++posItem) {
       for (int weight = 0; weight <= maxWeight; ++weight) {
           // weight of Item > remaining Weight
           // so that no room to add item
           if (weight < weights[posItem] ) {
               memoValues[posItem + 1][weight] = memoValues[posItem][weight];
           } else {
               memoValues[posItem + 1][weight] = std::max(
                   memoValues[posItem][weight],
                   memoValues[posItem + 1][weight -  weights[posItem]] 
                       + values[posItem]);
           }
       }
    }

    return memoValues[numItem][maxWeight];
}

int knapsack_with_duplication_fast_reuse(
    const int numItem,
    const int weights[],
    const int values[],
    const int maxWeight)
{
    int memoValues[2][maxWeight + 1];
    std::memset(memoValues, 0, sizeof(memoValues));

    for (int posItem = 0; posItem < numItem; ++posItem) {
       for (int weight = 0; weight <= maxWeight; ++weight) {
           const int current = posItem & 1;
           const int next =  (posItem + 1) & 1;
           // weight of Item > remaining Weight
           // so that no room to add item
           if (weight < weights[posItem] ) {
               memoValues[next][weight] = memoValues[current][weight];
           } else {
               memoValues[next][weight] = std::max(
                   memoValues[current][weight],
                   memoValues[next][weight -  weights[posItem]] 
                       + values[posItem]);
           }
       }
    }

    return memoValues[numItem & 1][maxWeight];
}
