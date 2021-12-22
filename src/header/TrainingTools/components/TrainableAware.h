/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#pragma once

#include <TrainingTools/components/Trainable.h>

namespace train {
class ModelAware {
protected:
  virtual void setModel(Trainable &model) = 0;
  virtual Trainable &getModel() = 0;
  virtual const Trainable &getModel() const = 0;

  const Vect &getLastWeights() const { return lastWeights; }
  void updateWeights(const Vect &weigths) { lastWeights = weigths; }

  const Vect &getLastGrad() const { return lastGrad; }
  void updateGradient(const Vect &grad) { lastGrad = grad; }

private:
  Vect lastWeights;
  Vect lastGrad;
};
} // namespace train
