#include <TestFunctions.h>
#include <TestSolver.h>

#include <TrainingTools/iterative/direction_optimizer/BisectionSearcher.h>
#include <TrainingTools/iterative/solvers/GradientDescend.h>

TEST(GradientDescendFixed, easy) {
  {
    train::test::EasyTestFunction2d function;
    train::test::check_train<train::GradientDescendFixed>(function);
  }

  {
    train::test::EasyTestFunction4d function;
    train::test::check_train<train::GradientDescendFixed>(function);
  }
}

TEST(GradientDescendFixed, medium) {
  {
    train::test::MediumTestFunction4d function;
    train::test::check_train<train::GradientDescendFixed>(
        function, false, [](train::GradientDescendFixed &solver) {
          solver.setOptimizationStep(0.5);
        });
  }

  {
    train::test::MediumTestFunction10d function;
    train::test::check_train<train::GradientDescendFixed>(
        function, false, [](train::GradientDescendFixed &solver) {
          solver.setOptimizationStep(0.5);
        });
  }
}

TEST(GradientDescendBisection, easy) {
  {
    train::test::EasyTestFunction2d function;
    train::test::check_train<train::GradientDescend<train::BisectionSearcher>>(
        function);
  }

  {
    train::test::EasyTestFunction4d function;
    train::test::check_train<train::GradientDescend<train::BisectionSearcher>>(
        function);
  }
}

TEST(GradientDescendBisection, medium) {
  {
    train::test::MediumTestFunction4d function;
    train::test::check_train<train::GradientDescend<train::BisectionSearcher>>(
        function);
  }

  {
    train::test::MediumTestFunction10d function;
    train::test::check_train<train::GradientDescend<train::BisectionSearcher>>(
        function);
  }
}

TEST(GradientDescendYunda, easy) {
  {
    train::test::EasyTestFunction2d function;
    train::test::check_train<train::GradientDescend<train::YundaSearcher>>(
        function);
  }

  {
    train::test::EasyTestFunction4d function;
    train::test::check_train<train::GradientDescend<train::YundaSearcher>>(
        function);
  }
}

TEST(GradientDescendYunda, medium) {
  {
    train::test::MediumTestFunction4d function;
    train::test::check_train<train::GradientDescend<train::YundaSearcher>>(
        function);
  }

  {
    train::test::MediumTestFunction10d function;
    train::test::check_train<train::GradientDescend<train::YundaSearcher>>(
        function);
  }
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
