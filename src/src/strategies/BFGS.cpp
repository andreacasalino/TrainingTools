/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#include <TrainingTools/strategies/BFGS.h>

namespace train {
void BFGS::updateInvHessian(const Vect &deltaWeight, const Vect &deltaGrad) {
  double rho = 1.0 / deltaWeight.dot(deltaGrad);
  Matr V = deltaGrad * deltaWeight.transpose();
  V *= -rho;
  V += Matr::Identity(deltaGrad.size(), deltaGrad.size());
  Matr Vtrasp = deltaWeight * deltaGrad.transpose();
  Vtrasp *= -rho;
  Vtrasp += Matr::Identity(deltaWeight.size(), deltaWeight.size());

  Matr newHessianApprox = Vtrasp * getInvHessianApprox() * V;
  Matr S = deltaWeight * deltaWeight.transpose();
  S *= rho;
  newHessianApprox += S;
  setInvHessianApprox(newHessianApprox);
}
} // namespace train
