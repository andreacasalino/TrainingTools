/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#pragma once

#include <TrainingTools/iterative/IterativeTrainer.h>
#include <TrainingTools/iterative/direction_optimizer/FixedStep.h>
#include <TrainingTools/iterative/direction_optimizer/YundaSearcher.h>
#include <TrainingTools/iterative/hessian_approximators/BFGS.h>
namespace train {
template <typename LineSearcherT = YundaSearcher,
          typename HessianApproximatorT = BFGS>
class QuasiNewton : public IterativeTrainer,
                    public LineSearcherT,
                    public HessianApproximatorT {
  static_assert(std::is_base_of<LineSearcher, LineSearcherT>::value,
                "LineSearcherT should be a form of LineSearcher");
  static_assert(
      std::is_base_of<HessianApproximator, HessianApproximatorT>::value,
      "HessianApproximatorT should be a form of HessianApproximator");

protected:
  void updateDirection() override {
    this->updateInvHessianApprox();
    Vect direction = this->getGradient();
    direction = this->getInvHessianApprox() * direction;
    direction *= -1.0;
    setDirection(direction);
  };
  void initDirection() override {
    Vect gradient = getGradient();
    this->initInvHessianApprox(gradient.size());
    setDirection(-gradient);
  };
};

using QuasiNewtonFixed = QuasiNewton<FixedStep>;
} // namespace train
