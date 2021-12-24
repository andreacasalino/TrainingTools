/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#pragma once

#include <TrainingTools/bases/IterativeTrainer.h>
#include <TrainingTools/strategies/BFGS.h>
#include <TrainingTools/strategies/YundaSearcher.h>

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
    direction = getInvHessianApprox() * direction;
    direction *= -1.f;
    setDirection(direction);
  };
  void initDirection() override {
    setDirection(getGradient());
    this->initInvHessianApprox(getParameters().size());
  };
  Vect descend() override { return this->optimize(getDirection()); };
};
} // namespace train
