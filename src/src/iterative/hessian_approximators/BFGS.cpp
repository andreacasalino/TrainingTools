/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#include <TrainingTools/strategies/BFGS.h>

namespace train {
std::unique_ptr<Matr> BFGS::updatedInvHessianApprox(const Vect &deltaParameters,
                                                    const Vect &deltaGradient) {
  double rho = 1.0 / deltaParameters.dot(deltaGradient);
  Matr V = deltaGradient * deltaParameters.transpose();
  V *= -rho;
  V += Matr::Identity(deltaGradient.size(), deltaGradient.size());
  Matr Vtrasp = deltaParameters * deltaGradient.transpose();
  Vtrasp *= -rho;
  Vtrasp += Matr::Identity(deltaParameters.size(), deltaParameters.size());

  std::unique_ptr<Matr> newHessianApprox =
      std::make_unique<Matr>(Vtrasp * getInvHessianApprox() * V);
  Matr S = deltaParameters * deltaParameters.transpose();
  S *= rho;
  *newHessianApprox += S;
  return newHessianApprox;
}
} // namespace train
