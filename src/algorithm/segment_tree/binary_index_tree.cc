#include "chap3/binary_index_tree.h"
#include <cstring>
#include <iostream>

int sum_binary_index_tree(int tree[], int index)
{
    int sum = 0;
    while (index > 0) {
        sum += tree[index];
        index -= index & (-index);
    }
    return sum;
}
/**
 * @brief 
 *
 * @param tree[] size + 1
 * @param size
 * @param index
 * @param value
 */
void add_binary_index_tree(
    int tree[], const int size, int index, const int value)
{
    while (index <= size) {
        tree[index] += value;
        index += index & (-index);
    }
}
/**
 * @brief 
 *
 * @param tree[] size + 1
 * @param data[]
 * @param size
 */
void init_binary_index_tree(int tree[], int data[], const int size)
{
    for (int i = 1; i <= size; ++i) {
        tree[i] = data[i];
    }
}

// num of swap
// data is permutation of sequence from 1 to n
long long int count_bubble_sort(int data[], const int size)
{
    // num of swaps
    // tree[i] detenos num of swap between i and i + 1
    int tree[size + 1];
    for (int i = 1; i <= size; ++i) {
        tree[i] = i;
    } 

    long long int numSwaps = 0;
    for (int j = 0; j < size; ++j) {
        numSwaps += j - sum_binary_index_tree(tree, data[j]);
        add_binary_index_tree(tree, size, data[j], 1);
    }
    return numSwaps;
}
