#include "Utils.h"
#include <TrainingTools/iterative/solvers/GradientDescend.h>

#include <iostream>

TEST_F(TestFunction2d, GradientDescend) {
  train::GradientDescend solver;
  solver.train(*this);
  checkEvolution();
}

TEST_F(TestFunction4d, GradientDescend) {
  train::GradientDescend solver;
  solver.train(*this);
  checkEvolution();
}

TEST_F(TestFunction10d, GradientDescend) {
  train::GradientDescend solver;
  solver.train(*this);
  checkEvolution();
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
