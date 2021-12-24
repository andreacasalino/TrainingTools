/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#include <TrainingTools/GradientDescendConjugate.h>

namespace train {
float FletcherReeves::getBeta() const {
  Vect grad = getModel().getGradient();
  const auto &last_grad = getLastGrad();
  return grad.dot(grad) / last_grad.dot(last_grad);
}

float PolakRibiere::getBeta() const {
  Vect grad = getModel().getGradient();
  const auto &last_grad = getLastGrad();
  return grad.dot(grad - last_grad) / last_grad.dot(last_grad);
}

float HestenesStiefel::getBeta() const {
  Vect grad = getModel().getGradient();
  Vect deltaGrad = grad - getLastGrad();
  return grad.dot(deltaGrad) / getLastGrad().dot(deltaGrad);
}

float DaiYuan::getBeta() const {
  Vect grad = getModel().getGradient();
  const auto &last_grad = getLastGrad();
  return grad.dot(grad) / last_grad.dot(grad - last_grad);
}
} // namespace train
