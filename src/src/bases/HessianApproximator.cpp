/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#include <TrainingTools/bases/HessianApproximator.h>

namespace train {
void HessianApproximator::updateInvHessianApprox() {
  auto deltaPar = getParameters() - getLastParameters();
  auto deltaGrad = getGradient() - getLastGradient();
  this->invHessianApprox = this->updatedInvHessianApprox(deltaPar, deltaGrad);
}
} // namespace train
