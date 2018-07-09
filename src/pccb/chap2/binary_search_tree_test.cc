#include <gtest/gtest.h>
#include "binary_search_tree.h"

TEST(binary_search_tree, insert)
{
    BinarySearchTreeNode* root = nullptr;
    root = insert(root, 3);
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 5);
    root = insert(root, 0);
    root = insert(root, 4);

    EXPECT_EQ(root->value, 3);
    EXPECT_EQ(root->left->value, 2);
    EXPECT_EQ(root->left->left->value, 1);
    EXPECT_EQ(root->left->left->left->value, 0);
    EXPECT_EQ(root->right->value, 5);
    EXPECT_EQ(root->right->left->value, 4);

    delete_binary_search_tree(root);
}

TEST(binary_search_tree, find)
{
    BinarySearchTreeNode* root = nullptr;
    root = insert(root, 3);
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 5);
    root = insert(root, 0);
    root = insert(root, 4);

    {
        const bool actual =  find(root, 3);
        EXPECT_EQ(true, actual);
    }
    {
        const bool actual =  find(root, 4);
        EXPECT_EQ(true, actual);
    }
    {
        const bool actual =  find(root, 8);
        EXPECT_EQ(false, actual);
    }
    delete_binary_search_tree(root);
}

TEST(binary_search_tree, remove_node_left_null)
{
    BinarySearchTreeNode* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 9);
    root = insert(root, 9);

    EXPECT_EQ(root->value, 10);
    EXPECT_EQ(root->left->value, 9);
    EXPECT_EQ(root->left->right->value, 9);

    root = remove(root, 9);
    EXPECT_EQ(root->value, 10);
    EXPECT_EQ(root->left->value, 9);

    delete_binary_search_tree(root);
}

TEST(binary_search_tree, remove_node_left_right_null)
{
    BinarySearchTreeNode* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 9);
    root = insert(root, 8);
    root = insert(root, 7);

    EXPECT_EQ(root->value, 10);
    EXPECT_EQ(root->left->value, 9);
    EXPECT_EQ(root->left->left->value, 8);
    EXPECT_EQ(root->left->left->left->value, 7);

    root = remove(root, 9);

    EXPECT_EQ(root->value, 10);
    EXPECT_EQ(root->left->value, 8);
    EXPECT_EQ(root->left->left->value, 7);

    delete_binary_search_tree(root);
}

TEST(binary_search_tree, remove_node_left_right_not_null)
{
    BinarySearchTreeNode* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 9);
    root = insert(root, 8);
    root = insert(root, 7);
    root = insert(root, 8);

    EXPECT_EQ(root->value, 10);
    EXPECT_EQ(root->left->value, 9);
    EXPECT_EQ(root->left->left->value, 8);
    EXPECT_EQ(root->left->left->left->value, 7);
    EXPECT_EQ(root->left->left->right->value, 8);

    root = remove(root, 9);
    EXPECT_EQ(root->value, 10);
    EXPECT_EQ(root->left->value, 8);
    EXPECT_EQ(root->left->left->value, 8);
    EXPECT_EQ(root->left->left->left->value, 7);

    delete_binary_search_tree(root);
}
