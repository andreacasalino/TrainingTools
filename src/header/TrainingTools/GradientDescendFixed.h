/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#pragma once

#include <TrainingTools/Error.h>
#include <TrainingTools/bases/IterativeTrainer.h>

namespace train {
/**
 * @brief At the every iteration the weights are updated in the following way:
    w_k+1 = w_k + step * gradient
 */
class GradientDescendFixed : public IterativeTrainer {
public:
  void setStep(const double step);

protected:
  void updateDirection() override { setDirection(getGradient()); };
  void initDirection() override { updateDirection(); };
  Vect descend() override;

private:
  double step = 0.5;
};
} // namespace train
