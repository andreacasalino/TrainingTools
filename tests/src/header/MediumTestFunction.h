#pragma once

#include <TestFunction.h>

namespace train::test {
template <std::size_t SpaceSize> class MediumFunction : public TestFunction {
public:
  MediumFunction() {
    // sample a random rotation matrix
    Matr rotation(SpaceSize, SpaceSize);
    rotation.setRandom();
    rotation.col(0) /= rotation.col(0).norm();
    for (Eigen::Index i = 1; i < SpaceSize; ++i) {
      for (Eigen::Index i2 = 0; i2 < i; ++i2) {
        rotation.col(i) -=
            rotation.col(i2).dot(rotation.col(i)) * rotation.col(i2);
      }
      rotation.col(i) /= rotation.col(i).norm();
    }
    A = Matr(SpaceSize, SpaceSize);
    A.setZero();
    bool caso = true;
    for (Eigen::Index i = 0; i < SpaceSize; ++i) {
      if (caso) {
        A(i, i) = 1.0;
      } else {
        A(i, i) = 0.5;
      }
      caso = !caso;
    }
    A = rotation * A * rotation.transpose();
  }

  std::size_t spaceSize() const override { return SpaceSize; }
  double evaluate(const Vect &point) const override {
    double val = 0.5 * point.transpose() * A * point;
    if (this->isMinimizing()) {
      return val;
    }
    return -val;
  };

  Vect getGradient() const override {
    Vect result = A * getParameters();
    if (this->isMinimizing()) {
      return result;
    }
    return -result;
  };

private:
  Matr A;
};
} // namespace train::test
