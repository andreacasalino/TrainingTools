#pragma once

#include <TrainingTools/MinimizeOrMaximizeAware.h>
#include <TrainingTools/ParametersAware.h>

namespace train::test {
class TestFunction : public ParametersAware, public MinimizeOrMaximizeAware {
public:
  Vect getParameters() const override;
  void setParameters(const Vect &point) override;

  virtual std::size_t spaceSize() const = 0;
  virtual double evaluate(const Vect &point) const = 0;

protected:
  Vect parameters;
};

} // namespace train::test
