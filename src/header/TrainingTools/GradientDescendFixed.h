/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#pragma once

#include <TrainingTools/Error.h>
#include <trainers/bases/IterativeTrainer.h>

namespace EFG::train {
/**
 * @brief At the every iteration the weights are updated in the following way:
    w_k+1 = w_k + step * gradient
 */
class GradientDescendFixed : public IterativeDescend {
public:
  void setStep(const float step) {
    if (step <= 0.f) {
      throw Error("Invalid step");
    }
    this->step = step;
  };

protected:
  void descend() override {
    auto direction = this->getGradient();
    direction *= this->step;
    auto w = this->model->getWeights();
    w -= direction;
    this->model->setWeights(w);
  };

private:
  float step = 0.5f;
};
} // namespace EFG::train
