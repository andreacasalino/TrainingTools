#include "Utils.h"
#include <TrainingTools/iterative/solvers/QuasiNewton.h>

#include <iostream>

TEST_F(TestFunction2d, QuasiNewtonFixed) {
  train::QuasiNewtonFixed solver;
  trainAndCheck(solver);
}

TEST_F(TestFunction2d, QuasiNewton) {
  train::QuasiNewton solver;
  trainAndCheck(solver);
}

TEST_F(TestFunction4d, QuasiNewtonFixed) {
  train::QuasiNewtonFixed solver;
  trainAndCheck(solver);
}

TEST_F(TestFunction4d, QuasiNewton) {
  train::QuasiNewton solver;
  trainAndCheck(solver);
}

TEST_F(TestFunction10d, QuasiNewtonFixed) {
  train::QuasiNewtonFixed solver;
  trainAndCheck(solver);
}

TEST_F(TestFunction10d, QuasiNewton) {
  train::QuasiNewton solver;
  trainAndCheck(solver);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
