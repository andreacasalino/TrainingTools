#include "Utils.h"
#include <TrainingTools/iterative/solvers/GradientDescend.h>

#include <iostream>

TEST_F(EasyTestFunction2d, GradientDescendFixed) {
  train::GradientDescendFixed solver;
  trainAndCheck(solver);
}

TEST_F(EasyTestFunction2d, GradientDescend) {
  train::GradientDescend solver;
  trainAndCheck(solver);
}

TEST_F(EasyTestFunction4d, GradientDescendFixed) {
  train::GradientDescendFixed solver;
  trainAndCheck(solver);
}

TEST_F(EasyTestFunction4d, GradientDescend) {
  train::GradientDescend solver;
  trainAndCheck(solver);
}

TEST_F(EasyTestFunction10d, GradientDescendFixed) {
  train::GradientDescendFixed solver;
  trainAndCheck(solver);
}

TEST_F(EasyTestFunction10d, GradientDescend) {
  train::GradientDescend solver;
  trainAndCheck(solver);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
