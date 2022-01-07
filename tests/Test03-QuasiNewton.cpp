#include <TestFunctions.h>
#include <TestSolver.h>

#include <TrainingTools/iterative/direction_optimizer/BisectionSearcher.h>
#include <TrainingTools/iterative/solvers/QuasiNewton.h>

TEST(QuasiNewtonFixed, EasyTestFunction2d) {
  train::test::EasyTestFunction2d function;
  train::test::check_train<train::QuasiNewtonFixed>(function);
}

TEST(QuasiNewtonFixed, EasyTestFunction4d) {
  train::test::EasyTestFunction4d function;
  train::test::check_train<train::QuasiNewtonFixed>(function);
}

TEST(QuasiNewtonFixed, EasyTestFunction10d) {
  train::test::EasyTestFunction10d function;
  train::test::check_train<train::QuasiNewtonFixed>(function);
}

TEST(QuasiNewtonBisection, EasyTestFunction2d) {
  train::test::EasyTestFunction2d function;
  train::test::check_train<train::QuasiNewton<train::BisectionSearcher>>(
      function);
}

TEST(QuasiNewtonBisection, EasyTestFunction4d) {
  train::test::EasyTestFunction4d function;
  train::test::check_train<train::QuasiNewton<train::BisectionSearcher>>(
      function);
}

TEST(QuasiNewtonBisection, EasyTestFunction10d) {
  train::test::EasyTestFunction10d function;
  train::test::check_train<train::QuasiNewton<train::BisectionSearcher>>(
      function);
}

TEST(QuasiNewtonYunda, EasyTestFunction2d) {
  train::test::EasyTestFunction2d function;
  train::test::check_train<train::QuasiNewton<train::YundaSearcher>>(function);
}

TEST(QuasiNewtonYunda, EasyTestFunction4d) {
  train::test::EasyTestFunction4d function;
  train::test::check_train<train::QuasiNewton<train::YundaSearcher>>(function);
}

TEST(QuasiNewtonYunda, EasyTestFunction10d) {
  train::test::EasyTestFunction10d function;
  train::test::check_train<train::QuasiNewton<train::YundaSearcher>>(function);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
