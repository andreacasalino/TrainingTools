#pragma once

#include <TrainingTools/ParametersAware.h>
#include <gtest/gtest.h>
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
    evolution.back().setRandom();
  }

  const std::vector<Vect> &getParametersEvolution() const { return evolution; }
  std::vector<double> getFunctionEvolution() const {
    std::vector<double> result;
    result.reserve(evolution.size());
    for (const auto &point : evolution) {
      result.emplace_back(0.5 * point.dot(point));
    }
    return result;
  }

private:
  std::vector<Vect> evolution;
};
} // namespace train::test
