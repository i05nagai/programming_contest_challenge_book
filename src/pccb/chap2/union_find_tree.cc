#include "pccb/chap2/union_find_tree.h"
#include <cassert>

void init_union_find(int rootNode[], int height[], const int numElement) {
    for (int elemIndex = 0; elemIndex < numElement; ++elemIndex) {
        rootNode[elemIndex] = elemIndex;
        height[elemIndex] = 0;
    }
}

int find_root_node(int rootNode[], int height[], const int elem) {
    // root of groups
    if (rootNode[elem] == elem) {
        return elem;
    } else {
        // update root
        rootNode[elem] = find_root_node(rootNode, height, rootNode[elem]); 
        return rootNode[elem];
    }
}

void unite_group(
    int rootNode[], int height[], const int elem1, const int elem2) {
    const int root1 = find_root_node(rootNode, height, elem1);
    const int root2 = find_root_node(rootNode, height, elem2);

    //same group
    if (root1 == root2) {
        return;
    }
    // merge tree
    if (height[root1] < height[root2]) {
        rootNode[root1] = root2;
    // group of root1 is higher than group of root2
    } else {
        rootNode[root2] = root1;
        if (height[root1] == height[root2]) {
            height[root1]++;
        }
    }
}

bool is_same_group(
    int rootNode[], int height[], const int elem1, const int elem2) {
    const int group1 = find_root_node(rootNode, height, elem1);
    const int group2 = find_root_node(rootNode, height, elem2);
    return group1 == group2;
}

int food_chain(
    const int types[], const int x[], const int y[], const int numInfo,
    const int numAnimals) {

    // Group A: 0 to numAnimals - 1
    // Group B: numAnimals to 2 numAnimals - 1
    // Group C: 2 numAnimals to 3 numAnimals - 1
    const int numElement = numAnimals * 3;
    int rootNode[numElement];
    int height[numElement];
    init_union_find(rootNode, height, numElement);

    int countInvalidInfo = 0;
    for (size_t info = 0; info < numInfo; ++info) {
        // x and y are valid
        if ((0 > x[info] || x[info] >= numAnimals)
            || (0 > y[info] || y[info] >= numAnimals)) {
            ++countInvalidInfo;
            continue;
        }

        // x and y are same kind
        if (types[info] == 1) {
            // is in differet group
            if (is_same_group(rootNode, height, x[info], y[info] + numAnimals)
                || is_same_group(rootNode, height, x[info], y[info] + numAnimals * 2)) {
                ++countInvalidInfo;
                continue;
            }
            unite_group(rootNode, height,
                        x[info], y[info]);
            unite_group(rootNode, height,
                        x[info] + numAnimals, y[info] + numAnimals);
            unite_group(rootNode, height,
                        x[info] + 2 * numAnimals, y[info] + 2 * numAnimals);
        // x and y are different kind
        } else if (types[info] == 2) {
            if (is_same_group(rootNode, height, x[info], y[info])
                || is_same_group(rootNode, height, x[info], y[info] + 2 * numAnimals)) {
                ++countInvalidInfo;
                continue;
            }
            unite_group(rootNode, height,
                        x[info], y[info] + numAnimals);
            unite_group(rootNode, height,
                        x[info] + numAnimals, y[info] + 2 * numAnimals);
            unite_group(rootNode, height,
                        x[info] + 2 * numAnimals, y[info]);
        } else {
            ++countInvalidInfo;
        }
    }
    return countInvalidInfo;
}
