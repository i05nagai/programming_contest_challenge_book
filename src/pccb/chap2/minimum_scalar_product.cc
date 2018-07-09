#include "pccb/chap2/minimum_scalar_product.h"
#include <algorithm>
#include <functional>

long long int minimum_scalar_product(int v1[], int v2[], const int numElements)
{
    std::sort(v1, v1 + numElements);
    std::sort(v2, v2 + numElements, std::greater<int>());

    long long int sum = 0;
    for (int i = 0; i < numElements; ++i) {
       sum +=  v1[i] * v2[i];
    }
    return sum;
}
