/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#pragma once

#include <TrainingTools/interfaces/ParametersAware.h>
#include <memory>

namespace train {
class ModelAware : public ParametersAware {
protected:
  void initModel(ParametersAware &model);
  void resetModel();

  Vect getParameters() const override { return this->model->getParameters(); };
  void setParameters(const Vect &parameters) override;

  Vect getGradient() const override { return this->model->getGradient(); };

  double getCostFunction() const override {
    return this->model->getCostFunction();
  };

  const Vect &getLastParameters() const { return *lastParameters; }
  const Vect &getLastGradient() const { return *lastGrad; }

private:
  ParametersAware *model = nullptr;

  std::unique_ptr<Vect> lastParameters;
  std::unique_ptr<Vect> lastGrad;
};
} // namespace train
