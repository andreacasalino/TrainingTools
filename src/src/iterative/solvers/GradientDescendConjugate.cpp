/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#include <TrainingTools/iterative/solvers/GradientDescendConjugate.h>

namespace train {
float FletcherReeves::getBeta() const {
  Vect grad = getGradient();
  const auto &last_grad = getLastGradient();
  return grad.dot(grad) / last_grad.dot(last_grad);
}

float PolakRibiere::getBeta() const {
  Vect grad = getGradient();
  const auto &last_grad = getLastGradient();
  return grad.dot(grad - last_grad) / last_grad.dot(last_grad);
}

float HestenesStiefel::getBeta() const {
  Vect grad = getGradient();
  Vect deltaGrad = grad - getLastGradient();
  return grad.dot(deltaGrad) / getLastGradient().dot(deltaGrad);
}

float DaiYuan::getBeta() const {
  Vect grad = getGradient();
  const auto &last_grad = getLastGradient();
  return grad.dot(grad) / last_grad.dot(grad - last_grad);
}
} // namespace train
