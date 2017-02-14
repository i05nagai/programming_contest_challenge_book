#include "chap2/fence_repair.h"
#include <algorithm>

int fence_repair(const int numFence, int fences[])
{
    std::sort(fences, fences + numFence);

    int num = numFence;
    int totalCost = 0;

    while (1 < num) {
        int firstMinIndex = 0;
        int secondMinIndex = 1;

        // fences[firstMinIndex] must be minimum
        if (fences[firstMinIndex] > fences[secondMinIndex]) {
            const int temp = fences[firstMinIndex];
            fences[firstMinIndex] = fences[secondMinIndex];
            fences[secondMinIndex] = temp;
        }

        //find minimum 
        for (int j = 2; j < num; ++j) {
            // update minimum
            if (fences[j] < fences[firstMinIndex]) {
                secondMinIndex = firstMinIndex;
                firstMinIndex = j;
            // update second minimum
            } else if (fences[j] < fences[secondMinIndex]) {
                secondMinIndex = j;
            }
        }

        // add cost
        const int cost = fences[firstMinIndex] + fences[secondMinIndex];
        totalCost += cost;

        // shrink array to numFence - 1
        if (firstMinIndex == num - 1) {
            const int temp = fences[firstMinIndex];
            fences[firstMinIndex] = fences[secondMinIndex];
            fences[secondMinIndex] = temp;
        }
        fences[firstMinIndex] = cost;
        fences[secondMinIndex] = fences[num - 1];
        num--;
    }

    return totalCost;
}
