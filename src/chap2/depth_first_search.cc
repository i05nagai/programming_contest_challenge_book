#include "chap2/depth_first_search.h"

bool depth_first_search(int* array, int size, int total, int i, int sum)
{
    if (i == size) {
        return sum == total;
    }

    //array[i] is not added
    if (depth_first_search(array, size, total, i + 1, sum)) {
        return true;
    }

    //array[i] is added
    if (depth_first_search(array, size, total, i + 1, sum + array[i])) {
        return true;
    }

    // otherwise
    return false;
}

