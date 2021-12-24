/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#include <TrainingTools/Error.h>
#include <TrainingTools/iterative/IterativeTrainer.h>
#include <iostream>
#include <math.h>
#include <memory>

namespace train {
void IterativeTrainer::setParametersTollerance(const double value) {
  if (value < 0) {
    throw Error("Negative tollerance value");
  }
  this->parametersTollerance = value;
};

void IterativeTrainer::setGradientTollerance(const double value) {
  if (value < 0) {
    throw Error("Negative tollerance value");
  }
  this->gradientTollerance = value;
};

namespace {
double l1Norm(const Vect &v) {
  double res = 0;
  const double *data = v.data();
  for (std::size_t k = 0; k < v.size(); ++k) {
    if (abs(data[k]) > res) {
      res = abs(data[k]);
    }
  }
  return res;
}

class TimeCounter {
public:
  TimeCounter(std::chrono::milliseconds &cumulatedTime)
      : start(std::chrono::high_resolution_clock::now()),
        cumulatedTime(cumulatedTime){};

  ~TimeCounter() {
    this->cumulatedTime +=
        std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::high_resolution_clock::now() - this->start);
  };

private:
#ifdef _MSC_VER
  std::chrono::high_resolution_clock::time_point start;
#else
  const std::chrono::time_point<std::chrono::system_clock> start;
#endif
  std::chrono::milliseconds &cumulatedTime;
};
}; // namespace

void IterativeTrainer::train_(ParametersAware &model) {
  this->elapsed = std::chrono::milliseconds(0);
  this->initModel(model);
  this->initDirection();
  this->resetIterations();
  while (getIterations() < getMaxIterations()) {
    if (this->printAdvnc) {
      std::cout << "\r iteration:  " << getIterations() << " / "
                << getMaxIterations() << std::endl;
    }
    TimeCounter counter(this->elapsed);
    auto deltaParameters = getParameters();
    this->optimize();
    if (l1Norm(getGradient()) < this->gradientTollerance) {
      break;
    }
    deltaParameters -= getParameters();
    if (l1Norm(deltaParameters) < this->parametersTollerance) {
      break;
    }
    this->updateDirection();
    this->incrementIterations();
  }
  resetModel();
}
} // namespace train
