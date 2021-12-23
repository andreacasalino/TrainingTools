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
  inline void descend() override {
    // Vect direction = this->invHessianApprox * this->getGradient();
    Vect direction = this->getGradient();
    direction = this->invHessianApprox * direction;
    direction *= -1.f;
    this->minimize(direction);
  };

  void update() override {
    this->HessianApproximatorT::update();
    this->IterativeDescend::update();
  };

  void reset() override {
    this->HessianApproximatorT::reset();
    this->IterativeDescend::update();
  };
};
} // namespace train
