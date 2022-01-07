#include <TestFunctions.h>
#include <TestSolver.h>

#include <TrainingTools/iterative/direction_optimizer/BisectionSearcher.h>
#include <TrainingTools/iterative/solvers/GradientDescendConjugate.h>

TEST(GradientDescendConjugateFixed, easy) {
  {
    train::test::EasyTestFunction2d function;
    train::test::check_train<train::GradientDescendConjugateFixed>(function);
  }

  {
    train::test::EasyTestFunction4d function;
    train::test::check_train<train::GradientDescendConjugateFixed>(function);
  }
}

TEST(GradientDescendConjugateFixed, medium) {
  {
    train::test::MediumTestFunction4d function;
    train::test::check_train<train::GradientDescendConjugateFixed>(
        function, false, [](train::GradientDescendConjugateFixed &solver) {
          solver.setOptimizationStep(0.5);
        });
  }

  {
    train::test::MediumTestFunction10d function;
    train::test::check_train<train::GradientDescendConjugateFixed>(
        function, false, [](train::GradientDescendConjugateFixed &solver) {
          solver.setOptimizationStep(0.5);
        });
  }
}

TEST(GradientDescendConjugateBisection, easy) {
  {
    train::test::EasyTestFunction2d function;
    train::test::check_train<
        train::GradientDescendConjugate<train::BisectionSearcher>>(function);
  }

  {
    train::test::EasyTestFunction4d function;
    train::test::check_train<
        train::GradientDescendConjugate<train::BisectionSearcher>>(function);
  }
}

TEST(GradientDescendConjugateBisection, medium) {
  {
    train::test::MediumTestFunction4d function;
    train::test::check_train<
        train::GradientDescendConjugate<train::BisectionSearcher>>(function);
  }

  {
    train::test::MediumTestFunction10d function;
    train::test::check_train<
        train::GradientDescendConjugate<train::BisectionSearcher>>(function);
  }
}

TEST(GradientDescendConjugateYunda, easy) {
  {
    train::test::EasyTestFunction2d function;
    train::test::check_train<
        train::GradientDescendConjugate<train::YundaSearcher>>(function);
  }

  {
    train::test::EasyTestFunction4d function;
    train::test::check_train<
        train::GradientDescendConjugate<train::YundaSearcher>>(function);
  }
}

TEST(GradientDescendConjugateYunda, medium) {
  {
    train::test::MediumTestFunction4d function;
    train::test::check_train<
        train::GradientDescendConjugate<train::YundaSearcher>>(function);
  }

  {
    train::test::MediumTestFunction10d function;
    train::test::check_train<
        train::GradientDescendConjugate<train::YundaSearcher>>(function);
  }
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
