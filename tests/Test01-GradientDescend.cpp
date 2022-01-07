#include <TestFunctions.h>
#include <TestSolver.h>

#include <TrainingTools/iterative/direction_optimizer/BisectionSearcher.h>
#include <TrainingTools/iterative/solvers/GradientDescend.h>

TEST(GradientDescendFixed, EasyTestFunction2d) {
  train::test::EasyTestFunction2d function;
  train::test::check_train<train::GradientDescendFixed>(function);
}

TEST(GradientDescendFixed, EasyTestFunction4d) {
  train::test::EasyTestFunction4d function;
  train::test::check_train<train::GradientDescendFixed>(function);
}

TEST(GradientDescendFixed, EasyTestFunction10d) {
  train::test::EasyTestFunction10d function;
  train::test::check_train<train::GradientDescendFixed>(function);
}

TEST(GradientDescendBisection, EasyTestFunction2d) {
  train::test::EasyTestFunction2d function;
  train::test::check_train<train::GradientDescend<train::BisectionSearcher>>(
      function);
}

TEST(GradientDescendBisection, EasyTestFunction4d) {
  train::test::EasyTestFunction4d function;
  train::test::check_train<train::GradientDescend<train::BisectionSearcher>>(
      function);
  ;
}

TEST(GradientDescendBisection, EasyTestFunction10d) {
  train::test::EasyTestFunction10d function;
  train::test::check_train<train::GradientDescend<train::BisectionSearcher>>(
      function);
}

TEST(GradientDescendYunda, EasyTestFunction2d) {
  train::test::EasyTestFunction2d function;
  train::test::check_train<train::GradientDescend<train::YundaSearcher>>(
      function);
}

TEST(GradientDescendYunda, EasyTestFunction4d) {
  train::test::EasyTestFunction4d function;
  train::test::check_train<train::GradientDescend<train::YundaSearcher>>(
      function);
  ;
}

TEST(GradientDescendYunda, EasyTestFunction10d) {
  train::test::EasyTestFunction10d function;
  train::test::check_train<train::GradientDescend<train::YundaSearcher>>(
      function);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
