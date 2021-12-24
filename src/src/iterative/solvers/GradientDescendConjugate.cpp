/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#include <TrainingTools/iterative/solvers/GradientDescendConjugate.h>

namespace train {
double FletcherReeves::getBeta() const {
  Vect grad = this->getGradient();
  return grad.dot(grad) / getLastGradient().dot(getLastGradient());
}

double PolakRibiere::getBeta() const {
  Vect grad = this->getGradient();
  return grad.dot(grad - getLastGradient()) /
         getLastGradient().dot(getLastGradient());
}

double HestenesStiefel::getBeta() const {
  Vect grad = this->getGradient();
  Vect deltaGrad = grad - getLastGradient();
  return grad.dot(deltaGrad) / getLastDirection().dot(deltaGrad);
}

double DaiYuan::getBeta() const {
  Vect grad = this->getGradient();
  return grad.dot(grad) / getLastDirection().dot(grad - getLastGradient());
}
} // namespace train
