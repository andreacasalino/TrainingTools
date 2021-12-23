/**
 * Author:    Andrea Casalino
 * Created:   22.12.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#pragma once

#include <TrainingTools/interfaces/ParametersAware.h>
#include <mutex>

namespace train {
class Trainer {
public:
  virtual ~Trainer() = default;

  void train(ParametersAware &model) {
    std::lock_guard<std::mutex> lock(train_mutex);
    train_(model);
  };

protected:
  Trainer() = default;

  virtual void train_(ParametersAware &model) = 0;

private:
  std::mutex train_mutex;
};
} // namespace train
