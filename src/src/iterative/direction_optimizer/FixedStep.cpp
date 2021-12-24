/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#include <TrainingTools/Error.h>
#include <TrainingTools/iterative/direction_optimizer/FixedStep.h>

namespace train {
void FixedStep::setOptimizationStep(const double step) {
  if (step < 0) {
    throw Error("Negative step is invalid");
  }
  this->step = step;
}

void FixedStep::optimize() {
  Vect delta = getDirection();
  delta *= step;
  setParameters(delta + getParameters());
};
} // namespace train
