#pragma once
#include "algorithm/graph/prim/prim.h"

namespace algorithm {
namespace graph {
constexpr int PRIM_INF = 100000;
int prim(int num_vertex, int**cost, int mincost[]);
} // namespace graph
} // namespace algorithm

