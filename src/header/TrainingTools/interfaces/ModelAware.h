/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#pragma once

#include <TrainingTools/interfaces/Trainable.h>

namespace train {
class ModelAware {
protected:
  void setModel(Trainable &model) { this->model = &model; };
  void resetModel() { this->model = nullptr; }
  Trainable &getModel() { return *model; };
  const Trainable &getModel() const { return *model; };

  const Vect &getLastWeights() const { return lastWeights; }
  void updateWeights(const Vect &weigths) { lastWeights = weigths; }

  const Vect &getLastGrad() const { return lastGrad; }
  void updateGradient(const Vect &grad) { lastGrad = grad; }

private:
  Trainable *model = nullptr;

  Vect lastWeights;
  Vect lastGrad;
};
} // namespace train
