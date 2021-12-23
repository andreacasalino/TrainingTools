/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#include <math.h>
#include <trainers/strategies/YundaSearcher.h>

namespace train {
constexpr float ALFA_MAX = 1.f;
constexpr float ALFA_MIN = 0.001f;
constexpr float C2 = 0.9f;
constexpr int ITER_MAX = 10;

double YundaSearcher::computeC1() const {
  double temp = pow(0.9f, static_cast<float>(this->doneIterations));
  return 0.0001 * (1.0 - temp) - temp;
}

void YundaSearcher::minimize(const Vect &direction) {
  float alfa = ALFA_MAX;
  float c1 = this->computeC1();
  std::size_t j = 0;
  float mu = 0.f;
  float gdOld = dot(this->lastGrad, direction);
  while ((j < ITER_MAX) && (alfa >= ALFA_MIN) && (alfa <= ALFA_MAX)) {
    this->model->setWeights(this->lastWeights + direction * alfa);
    float gd = dot(this->getGradient(), direction);
    // check condition in equation 7
    if (gd > gdOld * c1) {
      alfa = 0.5f * (mu + alfa);
      continue;
    }
    // check condition in equation 8
    if (gd < gdOld * C2) {
      mu = alfa;
      alfa = 2.f * mu;
      continue;
    }
    return;
  }
  // this->model->setWeights(makeVector(*this->lastWeights + direction * alfa));
  // float gd =
  // makeVectorXf(this->model->getGradient(this->getTrainSet())).dot(direction);
}
} // namespace train
