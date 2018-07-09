#include "pccb/chap3/two_pointer_technique/physics_experiment.h"
#include <gtest/gtest.h>

namespace pccb {
  TEST(physics_experiment_test, simple1)
  {
    const int num_ball = 1;
    const int radius = 10;
    const int height = 10;
    const int time = 100;
    const std::vector<double> actual = solve_physics_experiment(
        num_ball, radius, height, time);
    EXPECT_NEAR(4.95, actual[0], 10e-2);
  }

  TEST(physics_experiment_test, simple2)
  {
    const int num_ball = 2;
    const int radius = 10;
    const int height = 10;
    const int time = 100;
    const std::vector<double> actual = solve_physics_experiment(
        num_ball, radius, height, time);
    EXPECT_NEAR(4.95, actual[0], 10e-2);
    EXPECT_NEAR(10.20, actual[1], 10e-2);
  }
} // namespace pccb
