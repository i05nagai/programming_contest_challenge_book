#pragma once
#include <vector>

namespace pccb {
std::vector<std::pair<double, double>> crane(
    const int numCranes,
    const int numCommands,
    const int craneLengths[],
    const int points[],
    const double angles[]);
} // namespace pccb
