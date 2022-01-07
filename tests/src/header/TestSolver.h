#pragma once

#include <TestFunction.h>
#include <functional>
#include <iostream>

#include <gtest/gtest.h>

namespace train::test {

template <typename SolverT> class EvolutionAware : public SolverT {
public:
  EvolutionAware() = default;

  const std::vector<Vect> &getEvolution() const { return evolution; };

protected:
  void updateDirection() override {
    this->evolution.push_back(this->getParameters());
    this->SolverT::updateDirection();
  };
  void initDirection() override {
    this->evolution.clear();
    this->SolverT::initDirection();
  };

private:
  std::vector<Vect> evolution;
};

Vect get_initial_point(const std::size_t space_size) {
  Vect initial_point(space_size);
  bool caso = true;
  for (Eigen::Index i = 0; i < space_size; ++i) {
    if (caso) {
      initial_point(i) = 0.9;
    } else {
      initial_point(i) = -0.9;
    }
    caso = !caso;
  }
  return initial_point;
}

void check_evolution(TestFunction &function, const std::vector<Vect> &evolution,
                     bool strict) {
  auto it_ev = evolution.begin();
  auto it_prev = it_ev;
  ++it_ev;
  std::size_t iter = 0;
  for (it_ev; it_ev != evolution.end(); ++it_ev, ++it_prev, ++iter) {
    double value = function.evaluate(*it_ev);
    std::cout << "it-" << iter << ' ' << it_ev->transpose() << " -> " << value
              << std::endl;
    double value_prev = function.evaluate(*it_prev);
    if (strict) {
      if (function.isMaximizing()) {
        EXPECT_GE(value, value_prev);
      } else {
        EXPECT_LE(value, value_prev);
      }
    }
  }
  std::cout << std::endl;
  EXPECT_GE(evolution.front().norm(), evolution.back().norm());
  EXPECT_LE(evolution.back().norm(), 0.25);
}

template <typename SolverT>
void check_train(
    TestFunction &function, bool strict = false,
    const std::function<void(SolverT &)> solver_init = [](SolverT &) {
      return;
    }) {
  EvolutionAware<SolverT> solver;
  solver_init(solver);

  Vect initial_point = get_initial_point(function.spaceSize());
  std::cout << "Initial point: " << initial_point.transpose() << std::endl
            << std::endl;

  std::cout << "<---- Minimization ---->" << std::endl;
  function.minimize();
  solver.train(function);
  check_evolution(function, solver.getEvolution(), strict);

  std::cout << "<---- Maximization ---->" << std::endl;
  function.maximize();
  solver.train(function);
  check_evolution(function, solver.getEvolution(), strict);
}

template <typename SolverT>
void check_train_strict(
    TestFunction &function, const std::function<void(SolverT &)> solver_init =
                                [](SolverT &) { return; }) {
  check_train(function, true, solver_init);
}

} // namespace train::test
