/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#include <TrainingTools/Error.h>
#include <TrainingTools/bases/IterativeTrainer.h>
#include <iostream>
#include <math.h>
#include <memory>

namespace train {
void IterativeTrainer::setWeightsTollerance(const double value) {
  if (value < 0) {
    throw Error("Negative tollerance value");
  }
  this->weightsTollerance = value;
};

void IterativeTrainer::setGradientTollerance(const double value) {
  if (value < 0) {
    throw Error("Negative tollerance value");
  }
  this->gradientTollerance = value;
};

namespace {
double l1Norm(const Vect &v) {
  double res = 0.f;
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

void IterativeTrainer::train(Trainable &model) {
  this->elapsed = std::chrono::milliseconds(0);
  this->setModel(model);
  this->reset();
  std::unique_ptr<Vect> wOld =
      std::make_unique<Vect>(this->model->getWeights());
  std::unique_ptr<Vect> wAtt;
  for (std::size_t k = 0; k < this->maxIterations; ++k) {
    if (this->printAdvnc) {
      std::cout << "\r iteration:  " << k << " / " << this->maxIterations
                << std::endl;
    }
    TimeCounter counter(this->elapsed);
    this->descend();
    this->update();
    if (l1Norm(this->lastGrad) < this->gradientTollerance) {
      break;
    }
    wAtt = std::make_unique<Vect>(this->model->getWeights());
    if (l1Norm(*wOld - *wAtt) < this->weightsTollerance) {
      break;
    }
    std::swap(wOld, wAtt);
  }
  this->model = nullptr;
}

void IterativeTrainer::update() {
  this->incrementIterations();
  this->updateWeights(getModel().getParameters());
  this->updateGradient(getModel().getGradient());
};

void IterativeTrainer::reset() {
  this->resetIterations();
  this->updateWeights(getModel().getParameters());
  this->updateGradient(getModel().getGradient());
};
} // namespace train
