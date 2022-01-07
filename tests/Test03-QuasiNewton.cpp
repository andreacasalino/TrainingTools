#include <TestFunctions.h>
#include <TestSolver.h>

#include <TrainingTools/iterative/direction_optimizer/BisectionSearcher.h>
#include <TrainingTools/iterative/solvers/QuasiNewton.h>

TEST(QuasiNewtonFixed, easy) {
  {
    train::test::EasyTestFunction2d function;
    train::test::check_train<train::QuasiNewtonFixed>(function);
  }

  {
    train::test::EasyTestFunction4d function;
    train::test::check_train<train::QuasiNewtonFixed>(function);
  }
}

TEST(QuasiNewtonFixed, medium) {
  {
    train::test::MediumTestFunction4d function;
    train::test::check_train<train::QuasiNewtonFixed>(
        function, false, [](train::QuasiNewtonFixed &solver) {
          solver.setOptimizationStep(0.5);
        });
  }

  {
    train::test::MediumTestFunction10d function;
    train::test::check_train<train::QuasiNewtonFixed>(
        function, false, [](train::QuasiNewtonFixed &solver) {
          solver.setOptimizationStep(0.5);
        });
  }
}

TEST(QuasiNewtonBisection, easy) {
  {
    train::test::EasyTestFunction2d function;
    train::test::check_train<train::QuasiNewton<train::BisectionSearcher>>(
        function);
  }

  {
    train::test::EasyTestFunction4d function;
    train::test::check_train<train::QuasiNewton<train::BisectionSearcher>>(
        function);
  }
}

TEST(QuasiNewtonBisection, medium) {
  {
    train::test::MediumTestFunction4d function;
    train::test::check_train<train::QuasiNewton<train::BisectionSearcher>>(
        function);
  }

  {
    train::test::MediumTestFunction10d function;
    train::test::check_train<train::QuasiNewton<train::BisectionSearcher>>(
        function);
  }
}

TEST(QuasiNewtonYunda, easy) {
  {
    train::test::EasyTestFunction2d function;
    train::test::check_train<train::QuasiNewton<train::YundaSearcher>>(
        function);
  }

  {
    train::test::EasyTestFunction4d function;
    train::test::check_train<train::QuasiNewton<train::YundaSearcher>>(
        function);
  }
}

TEST(QuasiNewtonYunda, medium) {
  {
    train::test::MediumTestFunction4d function;
    train::test::check_train<train::QuasiNewton<train::YundaSearcher>>(
        function);
  }

  {
    train::test::MediumTestFunction10d function;
    train::test::check_train<train::QuasiNewton<train::YundaSearcher>>(
        function);
  }
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
