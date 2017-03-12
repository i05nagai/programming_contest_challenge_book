#pragma once

/**
 * @brief element is sequence of number from 0 to numElement-1
 *
 * @param rootNode[] each element denotes 
 *  root of the group to which the element belongs.
 * @param height[]
 * @param numElement
 */
void init_union_find(int rootNode[], int height[], const int numElement);
/**
 * @brief  
 *
 * @param rootNode[] each element denotes 
 *  root of the group to which the element belongs.
 * @param height[]
 * @param elem
 *
 * @return root of group which elem is contained.
 */
int find_root_node(int rootNode[], int height[], const int elem);
/**
 * @brief unite a group containing elem1 and a group containing elem2
 *
 * @param rootNode[]
 * @param height[]
 * @param elem1
 * @param elem2
 */
void unite_group(
    int rootNode[], int height[], const int elem1, const int elem2);
/**
 * @brief 
 *
 * @param rootNode
 * @param height
 * @param elem1
 * @param elem2
 *
 * @return true if elem1 and elem2 in a same group.
 */
bool is_same_group(
    int rootNode[], int height[], const int elem1, const int elem2);
/**
 * @brief 
 *
 * @param types[]
 * @param x[]
 * @param y[]
 * @param numInfo
 * @param numAnimals
 *
 * @return 
 */
int food_chain(
    const int types[], const int x[], const int y[], const int numInfo,
    const int numAnimals);
