#pragma once

struct BinarySearchTreeNode {
    // left->value is smaller than value
    BinarySearchTreeNode* left;
    // right->value is bigger than value
    BinarySearchTreeNode* right;
    int value;
};

/**
 * @brief recurrence.
 *
 * @param node
 * @param value
 *
 * @return node which should be holded by upper node
 */
BinarySearchTreeNode* insert(BinarySearchTreeNode* node, const int value);
/**
 * @brief 
 *
 * @param node
 * @param value
 *
 * @return node which should be holded by upper node
 */
BinarySearchTreeNode* remove(BinarySearchTreeNode* node, const int value);
void delete_binary_search_tree(BinarySearchTreeNode* node);
bool find(BinarySearchTreeNode* node, const int value);
