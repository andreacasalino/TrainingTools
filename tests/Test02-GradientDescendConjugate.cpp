#include "Utils.h"
#include <TrainingTools/iterative/solvers/GradientDescendConjugate.h>

#include <iostream>

TEST_F(TestFunction2d, GradientDescendConjugateFixed) {
  train::GradientDescendConjugateFixed solver;
  trainAndCheck(solver);
}

TEST_F(TestFunction2d, GradientDescendConjugate) {
  train::GradientDescendConjugate solver;
  trainAndCheck(solver);
}

TEST_F(TestFunction4d, GradientDescendConjugateFixed) {
  train::GradientDescendConjugateFixed solver;
  trainAndCheck(solver);
}

TEST_F(TestFunction4d, GradientDescendConjugate) {
  train::GradientDescendConjugate solver;
  trainAndCheck(solver);
}

TEST_F(TestFunction10d, GradientDescendConjugateFixed) {
  train::GradientDescendConjugateFixed solver;
  trainAndCheck(solver);
}

TEST_F(TestFunction10d, GradientDescendConjugate) {
  train::GradientDescendConjugate solver;
  trainAndCheck(solver);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
