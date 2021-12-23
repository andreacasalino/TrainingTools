/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#include <TrainingTools/GradientDescendFixed.h>

namespace train {
void GradientDescendFixed::setStep(const double step) {
  if (step <= 0) {
    throw Error("Invalid step");
  }
  this->step = step;
};

Vect GradientDescendFixed::descend() {
  auto result = getParameters();
  result += this->step * getDirection();
  return result;
};
} // namespace train
