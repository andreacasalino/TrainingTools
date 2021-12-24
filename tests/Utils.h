#pragma once

#include <TrainingTools/ParametersAware.h>
#include <gtest/gtest.h>
#include <iostream>
#include <vector>

namespace train::test {
template <std::size_t SpaceSize>
class TestFunction : public ParametersAware, public ::testing::Test {
public:
  Vect getParameters() const override { return evolution.back(); };
  void setParameters(const Vect &point) override {
    EXPECT_EQ(point.size(), SpaceSize);
    evolution.push_back(point);
  };

  Vect getGradient() const override { return evolution.back(); };

  void SetUp() override {
    evolution.emplace_back(SpaceSize);
    evolution.back().setOnes();
    bool caso = true;
    for (Eigen::Index i = 0; i < SpaceSize; ++i) {
      if (caso) {
        evolution.back()(i) = 0.9;
      } else {
        evolution.back()(i) = -0.9;
      }
      caso = !caso;
    }
    evolution.back() << 0.9, -0.85;
  }

  const std::vector<Vect> &getParametersEvolution() const { return evolution; }

  void checkEvolution() const {
    auto it_ev = evolution.begin();
    auto it_prev = it_ev;
    ++it_ev;
    for (it_ev; it_ev != evolution.end(); ++it_ev, ++it_prev) {
      double value = 0.5 * it_ev->dot(*it_ev);
      std::cout << value << std::endl;
      double value_prev = 0.5 * it_prev->dot(*it_prev);
      EXPECT_LE(value, value_prev);
    }
    std::cout << std::endl;
  }

private:
  std::vector<Vect> evolution;
};
} // namespace train::test
