#include "algorithm/segment_tree/a_simple_problem_with_integers.h"
#include <gtest/gtest.h>

namespace pccb {
TEST(a_simple_problem_with_integers_test, simple1)
{
  const int size = 10;
  int data[] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
  };
  std::vector<SolveASimpleProblemWithIntegersQuery> queries = {
    SolveASimpleProblemWithIntegersQuery('Q', {4, 4}),
    SolveASimpleProblemWithIntegersQuery('Q', {1, 10}),
    SolveASimpleProblemWithIntegersQuery('Q', {2, 4}),
    SolveASimpleProblemWithIntegersQuery('C', {3, 6, 3}),
    SolveASimpleProblemWithIntegersQuery('Q', {2, 4}),
  };
  const std::vector<long long> actuals = SolveASimpleProblemWithIntegers(
      data, size, queries);
  std::vector<int> expects = {
    4,
    55,
    9,
    15,
  };
  for (int i = 0; i < expects.size(); ++i) {
    const int expect = expects[i];
    const int actual = actuals[i];
    EXPECT_EQ(expect, actual);
  }
}

TEST(a_simple_problem_with_integers_test, SolveASimpleProblemWithIntegersWithBITSimple)
{
  const int size = 10;
  int data[] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
  };
  std::vector<SolveASimpleProblemWithIntegersQuery> queries = {
    SolveASimpleProblemWithIntegersQuery('Q', {4, 4}),
    SolveASimpleProblemWithIntegersQuery('Q', {1, 10}),
    SolveASimpleProblemWithIntegersQuery('Q', {2, 4}),
    SolveASimpleProblemWithIntegersQuery('C', {3, 6, 3}),
    SolveASimpleProblemWithIntegersQuery('Q', {2, 4}),
  };
  const std::vector<long long> actuals = SolveASimpleProblemWithIntegersWithBIT(
      data, size, queries);
  std::vector<long long> expects = {
    4,
    55,
    9,
    15,
  };
  for (int i = 0; i < expects.size(); ++i) {
    const long long expect = expects[i];
    const long long actual = actuals[i];
    EXPECT_EQ(expect, actual);
  }
}
} // namespace pccb

