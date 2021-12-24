#include "Utils.h"
#include <TrainingTools/iterative/solvers/GradientDescend.h>

#include <iostream>

using TestFunction2d = train::test::TestFunction<2>;
using TestFunction4d = train::test::TestFunction<4>;
using TestFunction10d = train::test::TestFunction<10>;

TEST_F(TestFunction2d, GradientDescendFixed) {
  train::GradientDescendFixed solver;
  solver.train(*this);
  checkEvolution();
}

TEST_F(TestFunction4d, GradientDescendFixed) {
  train::GradientDescendFixed solver;
  solver.train(*this);
  checkEvolution();
}

TEST_F(TestFunction10d, GradientDescendFixed) {
  train::GradientDescendFixed solver;
  solver.train(*this);
  checkEvolution();
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
