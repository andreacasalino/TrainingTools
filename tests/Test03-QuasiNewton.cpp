#include "Utils.h"
#include <TrainingTools/iterative/solvers/QuasiNewton.h>

#include <iostream>

TEST_F(EasyTestFunction2d, QuasiNewtonFixed) {
  train::QuasiNewtonFixed solver;
  trainAndCheck(solver);
}

TEST_F(MediumTestFunction2d, QuasiNewton) {
  train::QuasiNewton solver;
  trainAndCheck(solver);
}

TEST_F(EasyTestFunction4d, QuasiNewtonFixed) {
  train::QuasiNewtonFixed solver;
  trainAndCheck(solver);
}

// TEST_F(MediumTestFunction4d, QuasiNewton) {
//   train::QuasiNewton solver;
//   trainAndCheck(solver);
// }

TEST_F(EasyTestFunction10d, QuasiNewtonFixed) {
  train::QuasiNewtonFixed solver;
  trainAndCheck(solver);
}

// TEST_F(MediumTestFunction10d, QuasiNewton) {
//   train::QuasiNewton solver;
//   trainAndCheck(solver);
// }

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
