/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#include <TrainingTools/iterative/direction_optimizer/YundaSearcher.h>
#include <math.h>

namespace train {
namespace {
constexpr double ALFA_MAX = 1.0;
constexpr double ALFA_MIN = 0.001;
constexpr double C2 = 0.9;
constexpr int ITER_MAX = 50;
} // namespace

double YundaSearcher::computeC1() const {
  double temp = pow(0.9, static_cast<double>(getIterations()));
  return 0.0001 * (1.0 - temp) - temp;
}

void YundaSearcher::optimize() {
  double alfa = ALFA_MAX;
  double c1 = this->computeC1();
  std::size_t j = 0;
  double mu = 0;
  const auto &direction = getDirection();
  double gdOld = getLastGradient().dot(direction);
  Vect initialParameters = getParameters();
  while ((j < ITER_MAX) && (alfa >= ALFA_MIN) && (alfa <= ALFA_MAX)) {
    setParameters(initialParameters + direction * alfa);
    double gd = getGradient().dot(direction);
    // check condition in equation 7
    if (gd > gdOld * c1) {
      alfa = 0.5 * (mu + alfa);
      ++j;
      continue;
    }
    // check condition in equation 8
    if (gd < gdOld * C2) {
      mu = alfa;
      alfa = 2.0 * mu;
      ++j;
      continue;
    }
    return;
  }
}
} // namespace train
