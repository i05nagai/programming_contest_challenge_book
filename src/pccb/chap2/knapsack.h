#pragma once

/**
 * @brief 
 *
 * @param numItem
 * @param weights[]
 * @param values[]
 * @param posItem
 * @param remainingWeight
 *
 * @return max value
 */
int knapsack_simple(
    const int numItem,
    const int weights[],
    const int values[],
    int posItem,
    int remainingWeight);
/**
 * @brief 
 *
 * @param numItem
 * @param weights[]
 * @param values[]
 * @param posItem
 * @param remainingWeight
 *
 * @return max value
 */
int knapsack_memoization(
    const int numItem,
    const int weights[],
    const int values[],
    int posItem,
    int remainingWeight);
/**
 * @brief 
 *
 * @param numItem
 * @param weights[]
 * @param values[]
 * @param posItem
 * @param remainingWeight
 *
 * @return max value
 */
int knapsack_dynamic_programming(
    const int numItem,
    const int weights[],
    const int values[],
    int posItem,
    int remainingWeight);
