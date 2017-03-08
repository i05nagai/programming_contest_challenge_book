#include "binary_search_tree.h"


BinarySearchTreeNode* remove(BinarySearchTreeNode* node, const int value)
{
    if (node == nullptr) {
        return nullptr;
    } else if (value < node->value) {
        node->left = remove(node->left, value);
        return node;
    } else if (value < node->value) {
        node->right = remove(node->right, value);
        return node;
    // find removee
    } else if (node->left == nullptr) {
        BinarySearchTreeNode* temp = node->right;
        delete node;
        return temp;
    // and node->left is not null
    } else if (node->left->right == nullptr) {
        BinarySearchTreeNode* temp = node->left;
        delete node;
        return temp;
    // and node->left->right is not null
    } else {
        // search node
        BinarySearchTreeNode* p;
        for (p = node->left; p->right->right != nullptr; p = p->right);
        // p->right has maximum node in the left side from this node
        // p->rigth->right is null
        BinarySearchTreeNode* replacer = p->right;
        p->right = replacer->left;
        replacer->left = node->left;
        replacer->right = node->right;
        delete node;
        return replacer;
    }
}

BinarySearchTreeNode* insert(BinarySearchTreeNode* node, const int value)
{
    if (node == nullptr) {
        node = new BinarySearchTreeNode;
        node->value = value;
        node->left = nullptr;
        node->right = nullptr;
        return node;
    // node is not null
    } else if (value < node->value) {
        node->left = insert(node->left, value);
        return node;
    // included value == node->value
    } else {
        node->right = insert(node->right, value);
        return node;
    }
}

bool find(BinarySearchTreeNode* node, const int value)
{
    if (node == nullptr) {
        // not found
        return false;
    }

    // node is not null
    if (value < node->value) {
        return find(node->left, value);
    } else if (value > node->value) {
        return find(node->right, value);
    } else {
        return true;
    }
}

void delete_binary_search_tree(BinarySearchTreeNode* node)
{
    if (node == nullptr) {
        return;
    }
    delete_binary_search_tree(node->left);
    delete_binary_search_tree(node->right);
    delete node;
}
