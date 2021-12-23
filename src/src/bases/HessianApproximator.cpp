/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#include <TrainingTools/bases/HessianApproximator.h>

namespace train {
void HessianApproximator::update() {
  this->updateInvHessian(getModel().getParameters() - getLastWeights(),
                         getModel().getGradient() - getLastGrad());
}

void HessianApproximator::reset() {
  Eigen::Index size =
      static_cast<Eigen::Index>(getModel().getParameters().size());
  this->invHessianApprox = Matr::Identity(size, size);
}
} // namespace train
