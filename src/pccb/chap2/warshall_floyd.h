#pragma once
#include <vector>

constexpr int WARSHALL_FLOYD_INF = 1000000;

void warshall_floyd(
    std::vector<std::vector<int>>& dist, const int numVertex);
