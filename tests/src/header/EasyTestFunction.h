#pragma once

#include <TestFunction.h>

namespace train::test {
template <std::size_t SpaceSize> class EasyFunction : public TestFunction {
public:
  std::size_t spaceSize() const override { return SpaceSize; }
  double evaluate(const Vect &point) const override {
    double val = 0.5 * point.dot(point);
    if (this->isMinimizing()) {
      return val;
    }
    return -val;
  };

  Vect getGradient() const override {
    if (this->isMinimizing()) {
      return parameters;
    }
    return -parameters;
  };
};
} // namespace train::test
