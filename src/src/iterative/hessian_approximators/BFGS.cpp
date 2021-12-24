/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#include <TrainingTools/iterative/hessian_approximators/BFGS.h>

namespace train {
std::unique_ptr<Matr> BFGS::updatedInvHessianApprox(const Vect &deltaParameters,
                                                    const Vect &deltaGradient) {
  double rho = 1.0 / deltaParameters.dot(deltaGradient);
  Matr V = deltaGradient * deltaParameters.transpose();
  V *= -rho;
  V += Matr::Identity(deltaParameters.size(), deltaParameters.size());
  Matr Vtrasp = deltaParameters * deltaGradient.transpose();
  Vtrasp *= -rho;
  Vtrasp += Matr::Identity(deltaParameters.size(), deltaParameters.size());

  std::unique_ptr<Matr> new_hessian =
      std::make_unique<Matr>(Vtrasp * getInvHessianApprox() * V);
  Matr S = deltaParameters * deltaParameters.transpose();
  S *= rho;
  *new_hessian += S;
  return new_hessian;
}
} // namespace train
