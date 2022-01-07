/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#include <TrainingTools/iterative/direction_optimizer/BisectionSearcher.h>

namespace train {
namespace {
constexpr double ALFA_INITIAL = 1.0;
constexpr double ALFA_MIN = 0.001;
} // namespace

void BisectionSearcher::optimize() {
  double alfa = ALFA_INITIAL;
  const auto &direction = getDirection();
  Vect initialParameters = getParameters();
  double gNormInitial = getLastGradient().norm();
  std::size_t j = 0;
  while ((j < bisection_trials) && (alfa >= ALFA_MIN)) {
    setParameters(initialParameters + direction * alfa);
    double gNorm = getGradient().norm();
    if (gNorm < gNormInitial) {
      return;
    }
    alfa *= 0.5;
    ++j;
  }
}
} // namespace train
