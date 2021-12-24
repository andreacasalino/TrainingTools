#pragma once

#include <TrainingTools/ParametersAware.h>
#include <TrainingTools/Trainer.h>
#include <gtest/gtest.h>
#include <iostream>
#include <vector>

namespace train::test {
class TestFunctionConcrete : public ParametersAware {
public:
  Vect getParameters() const override { return parameters; };
  void setParameters(const Vect &point) override { parameters = point; };

  virtual std::size_t spaceSize() const = 0;
  virtual double evaluate(const Vect &point) const = 0;

protected:
  Vect parameters;
};

template <std::size_t SpaceSize>
class EasyFunction : public TestFunctionConcrete {
public:
  std::size_t spaceSize() const override { return SpaceSize; }
  double evaluate(const Vect &point) const override {
    return 0.5 * point.dot(point);
  };

  Vect getGradient() const override { return parameters; };
};

template <std::size_t SpaceSize>
class MediumFunction : public TestFunctionConcrete {
public:
  std::size_t spaceSize() const override { return SpaceSize; }
  double evaluate(const Vect &point) const override {
    return 0.1 * cos(point.norm()) + 0.5 * point.dot(point);
  };

  Vect getGradient() const override {
    double norm = parameters.norm();
    return ((1.0 - 0.1 * sin(norm)) / norm) * parameters;
  };
};

template <typename FunctionT>
class TestFunction : public ParametersAware, public ::testing::Test {
public:
  Vect getParameters() const override { return function->getParameters(); };
  void setParameters(const Vect &point) override {
    function->setParameters(point);
    evolution.push_back(point);
  };

  Vect getGradient() const override { return function->getGradient(); };

  void SetUp() override {
    const TestFunctionConcrete *function_ptr =
        dynamic_cast<const TestFunctionConcrete *>(function.get());
    const auto spaceSize = function_ptr->spaceSize();
    Vect initial_point(spaceSize);
    bool caso = true;
    for (Eigen::Index i = 0; i < spaceSize; ++i) {
      if (caso) {
        initial_point(i) = 0.9;
      } else {
        initial_point(i) = -0.9;
      }
      caso = !caso;
    }
    setParameters(initial_point);
    std::cout << "Initial point: " << getParameters().transpose() << std::endl
              << std::endl;
  }

  const std::vector<Vect> &getParametersEvolution() const { return evolution; }

  void checkEvolution() {
    const TestFunctionConcrete *function_ptr =
        dynamic_cast<const TestFunctionConcrete *>(function.get());
    auto it_ev = evolution.begin();
    auto it_prev = it_ev;
    ++it_ev;
    for (it_ev; it_ev != evolution.end(); ++it_ev, ++it_prev) {
      double value = function_ptr->evaluate(*it_ev);
      std::cout << value << std::endl;
      double value_prev = function_ptr->evaluate(*it_prev);
      // EXPECT_LE(value, value_prev);
    }
    std::cout << std::endl;
  }

  void trainAndCheck(Trainer &solver) {
    solver.train(*this);
    checkEvolution();
  }

private:
  std::vector<Vect> evolution;
  std::unique_ptr<ParametersAware> function = std::make_unique<FunctionT>();
};
} // namespace train::test

using EasyTestFunction2d =
    train::test::TestFunction<train::test::EasyFunction<2>>;
using EasyTestFunction4d =
    train::test::TestFunction<train::test::EasyFunction<4>>;
using EasyTestFunction10d =
    train::test::TestFunction<train::test::EasyFunction<10>>;

using MediumTestFunction2d =
    train::test::TestFunction<train::test::MediumFunction<2>>;
using MediumTestFunction4d =
    train::test::TestFunction<train::test::MediumFunction<4>>;
using MediumTestFunction10d =
    train::test::TestFunction<train::test::MediumFunction<10>>;
