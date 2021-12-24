/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#include <TrainingTools/iterative/hessian_approximators/HessianApproximator.h>

namespace train {
void HessianApproximator::updateInvHessianApprox() {
  Vect deltaPar = getParameters() - getLastParameters();
  Vect deltaGrad = getGradient() - getLastGradient();
  this->invHessianApprox = this->updatedInvHessianApprox(deltaPar, deltaGrad);
}
} // namespace train
