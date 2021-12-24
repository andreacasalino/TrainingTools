#include "Utils.h"
#include <TrainingTools/iterative/solvers/GradientDescend.h>

#include <iostream>

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
