/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#pragma once

#include <TrainingTools/interfaces/ModelAware.h>
#include <TrainingTools/interfaces/Updatable.h>

namespace train {
/**
 * @brief The base for an object storing the local hessian approximation of the
 * function to optimize
 */
class HessianApproximator : public virtual ModelAware,
                            public virtual Updatable {
protected:
  void update() override;
  void reset() override;

  virtual void updateInvHessian(const Vect &deltaWeight,
                                const Vect &deltaGrad) = 0;

  const Matr &getInvHessianApprox() const { return invHessianApprox; }
  void setInvHessianApprox(const Matr &hessian) { invHessianApprox = hessian; };

private:
  Matr invHessianApprox;
};
} // namespace train
