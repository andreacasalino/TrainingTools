#include "Utils.h"
#include <TrainingTools/iterative/solvers/GradientDescendConjugate.h>

#include <iostream>

TEST_F(EasyTestFunction2d, GradientDescendConjugateFixed) {
  train::GradientDescendConjugateFixed solver;
  trainAndCheck(solver);
}

TEST_F(MediumTestFunction2d, GradientDescendConjugate) {
  train::GradientDescendConjugate solver;
  trainAndCheck(solver);
}

TEST_F(EasyTestFunction4d, GradientDescendConjugateFixed) {
  train::GradientDescendConjugateFixed solver;
  trainAndCheck(solver);
}

TEST_F(MediumTestFunction4d, GradientDescendConjugate) {
  train::GradientDescendConjugate solver;
  trainAndCheck(solver);
}

TEST_F(EasyTestFunction10d, GradientDescendConjugateFixed) {
  train::GradientDescendConjugateFixed solver;
  trainAndCheck(solver);
}

TEST_F(MediumTestFunction10d, GradientDescendConjugate) {
  train::GradientDescendConjugate solver;
  trainAndCheck(solver);
}

TEST_F(MediumTestFunction10d, GradientDescendConjugate_PolakRibiere) {
  train::GradientDescendConjugate<train::YundaSearcher, train::PolakRibiere>
      solver;
  trainAndCheck(solver);
}

TEST_F(MediumTestFunction10d, GradientDescendConjugate_HestenesStiefel) {
  train::GradientDescendConjugate<train::YundaSearcher, train::HestenesStiefel>
      solver;
  trainAndCheck(solver);
}

TEST_F(MediumTestFunction10d, GradientDescendConjugate_DaiYuan) {
  train::GradientDescendConjugate<train::YundaSearcher, train::DaiYuan> solver;
  trainAndCheck(solver);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
