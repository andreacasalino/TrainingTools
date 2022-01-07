#include <TestFunctions.h>
#include <TestSolver.h>

#include <TrainingTools/iterative/direction_optimizer/BisectionSearcher.h>
#include <TrainingTools/iterative/solvers/GradientDescendConjugate.h>

TEST(GradientDescendConjugateFixed, EasyTestFunction2d) {
  train::test::EasyTestFunction2d function;
  train::test::check_train<train::GradientDescendConjugateFixed>(function);
}

TEST(GradientDescendConjugateFixed, EasyTestFunction4d) {
  train::test::EasyTestFunction4d function;
  train::test::check_train<train::GradientDescendConjugateFixed>(function);
}

TEST(GradientDescendConjugateFixed, EasyTestFunction10d) {
  train::test::EasyTestFunction10d function;
  train::test::check_train<train::GradientDescendConjugateFixed>(function);
}

TEST(GradientDescendConjugateBisection, EasyTestFunction2d) {
  train::test::EasyTestFunction2d function;
  train::test::check_train<
      train::GradientDescendConjugate<train::BisectionSearcher>>(function);
}

TEST(GradientDescendConjugateBisection, EasyTestFunction4d) {
  train::test::EasyTestFunction4d function;
  train::test::check_train<
      train::GradientDescendConjugate<train::BisectionSearcher>>(function);
}

TEST(GradientDescendConjugateBisection, EasyTestFunction10d) {
  train::test::EasyTestFunction10d function;
  train::test::check_train<
      train::GradientDescendConjugate<train::BisectionSearcher>>(function);
}

TEST(GradientDescendConjugateYunda, EasyTestFunction2d) {
  train::test::EasyTestFunction2d function;
  train::test::check_train<
      train::GradientDescendConjugate<train::YundaSearcher>>(function);
}

TEST(GradientDescendConjugateYunda, EasyTestFunction4d) {
  train::test::EasyTestFunction4d function;
  train::test::check_train<
      train::GradientDescendConjugate<train::YundaSearcher>>(function);
}

TEST(GradientDescendConjugateYunda, EasyTestFunction10d) {
  train::test::EasyTestFunction10d function;
  train::test::check_train<
      train::GradientDescendConjugate<train::YundaSearcher>>(function);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
