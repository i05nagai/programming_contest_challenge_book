#pragma once

/**
 * @brief 
 *
 * 1 <= numItem <= 100
 * 1 <= weigth <= 100
 * 1 <= value <= 100
 * 1 <= maxWeight <= 100000
 *
 * @param numItem
 * @param weigths[]
 * @param values[]
 * @param maxWeight
 *
 * @return maximum value of knapsack
 */
int knapsack_with_duplication(
    const int numItem,
    const int weights[],
    const int values[],
    const int maxWeight);
/**
 * @brief 
 *
 * 1 <= numItem <= 100
 * 1 <= weigth <= 100
 * 1 <= value <= 100
 * 1 <= maxWeight <= 100000
 *
 * @param numItem
 * @param weigths[]
 * @param values[]
 * @param maxWeight
 *
 * @return maximum value of knapsack
 */
int knapsack_with_duplication_simple(
    const int numItem,
    const int weights[],
    const int values[],
    const int maxWeight);
/**
 * @brief 
 *
 * 1 <= numItem <= 100
 * 1 <= weigth <= 100
 * 1 <= value <= 100
 * 1 <= maxWeight <= 100000
 *
 * @param numItem
 * @param weigths[]
 * @param values[]
 * @param maxWeight
 *
 * @return maximum value of knapsack
 */
int knapsack_with_duplication_fast(
    const int numItem,
    const int weights[],
    const int values[],
    const int maxweight);
/**
 * @brief 
 *
 * 1 <= numItem <= 100
 * 1 <= weigth <= 100
 * 1 <= value <= 100
 * 1 <= maxWeight <= 100000
 *
 * @param numItem
 * @param weigths[]
 * @param values[]
 * @param maxWeight
 *
 * @return maximum value of knapsack
 */
int knapsack_with_duplication_fast_reuse(
    const int numItem,
    const int weights[],
    const int values[],
    const int maxweight);
