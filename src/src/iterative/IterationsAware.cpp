/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#include <TrainingTools/Error.h>
#include <TrainingTools/iterative/IterationsAware.h>

namespace train {
void IterationsAware::setMaxIterations(const std::size_t iter) {
  if (iter < 10) {
    throw Error("Too few iterations");
  }
  this->maxIterations = iter;
};
} // namespace train
