#pragma once
#include <vector>

namespace pccb {
  class SolveASimpleProblemWithIntegersQuery {
  public:
    SolveASimpleProblemWithIntegersQuery(
        const char type, std::vector<int> data)
      : Type(type), Data(data) {
    };
    char Type;
    std::vector<int> Data;
  };
  std::vector<long long> SolveASimpleProblemWithIntegers(
    int data[],
    const int size,
    const std::vector<SolveASimpleProblemWithIntegersQuery>& query);
  std::vector<long long> SolveASimpleProblemWithIntegersWithBIT(
    int data[],
    const int size,
    const std::vector<SolveASimpleProblemWithIntegersQuery>& query);
} // namespace pccb
