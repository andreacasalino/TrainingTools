#include "Utils.h"
#include <TrainingTools/iterative/solvers/GradientDescendConjugate.h>

#include <iostream>

TEST_F(MediumTestFunction2d, GradientDescendConjugateFixed) {
  train::GradientDescendConjugateFixed solver;
  trainAndCheck(solver);
}

TEST_F(MediumTestFunction2d, GradientDescendConjugate) {
  train::GradientDescendConjugate solver;
  trainAndCheck(solver);
}

TEST_F(MediumTestFunction4d, GradientDescendConjugateFixed) {
  train::GradientDescendConjugateFixed solver;
  trainAndCheck(solver);
}

TEST_F(MediumTestFunction4d, GradientDescendConjugate) {
  train::GradientDescendConjugate solver;
  trainAndCheck(solver);
}

TEST_F(MediumTestFunction10d, GradientDescendConjugateFixed) {
  train::GradientDescendConjugateFixed solver;
  trainAndCheck(solver);
}

TEST_F(MediumTestFunction10d, GradientDescendConjugate) {
  train::GradientDescendConjugate solver;
  trainAndCheck(solver);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
