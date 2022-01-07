/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#pragma once

#include <TrainingTools/MinimizeOrMaximizeAware.h>
#include <TrainingTools/ParametersAware.h>
#include <memory>

namespace train {
class ModelAware : public ParametersAware,
                   public virtual MinimizeOrMaximizeAware {
protected:
  void initModel(ParametersAware &model);
  void resetModel();

  const ParametersAware *getModel() const { return model; }

  Vect getParameters() const override { return this->model->getParameters(); };
  void setParameters(const Vect &parameters) override;

  Vect getGradient() const override;

  const Vect &getLastParameters() const { return *lastParameters; }
  const Vect &getLastGradient() const { return *lastGrad; }

private:
  ParametersAware *model = nullptr;

  std::unique_ptr<Vect> lastParameters;
  std::unique_ptr<Vect> lastGrad;
};
} // namespace train
