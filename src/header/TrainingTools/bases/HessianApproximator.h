/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#pragma once

#include <TrainingTools/bases/ModelAware.h>
#include <memory>

namespace train {
/**
 * @brief The base for an object storing the local hessian approximation of the
 * function to optimize
 */
class HessianApproximator : public virtual ModelAware {
protected:
  virtual std::unique_ptr<Matr>
  updatedInvHessianApprox(const Vect &deltaParameters,
                          const Vect &deltaGradient) = 0;
  void updateInvHessianApprox();
  void initInvHessianApprox(Eigen::Index size) {
    invHessianApprox = std::make_unique<Matr>(size, size);
  };

  const Matr &getInvHessianApprox() const { return *invHessianApprox; }

private:
  std::unique_ptr<Matr> invHessianApprox;
};
} // namespace train
