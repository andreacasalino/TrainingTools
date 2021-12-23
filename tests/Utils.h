#pragma once

#include <TrainingTools/interfaces/Trainable.h>

namespace train::test {
class TestFunction : public train::Trainable {
public:
  Vect getParameters() override;
  void setParameters(const Vect &) override;

  Vect getGradient() override;

  double getCostFunction() override;
};
} // namespace train::test
