#pragma once
#include <vector>

namespace pccb {
std::vector<std::pair<double, double>> SolveCrane(
    const int numCranes,
    const int numCommands,
    const int craneLengths[],
    const int points[],
    const int angles[]);
} // namespace pccb
