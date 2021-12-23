/**
 * Author:    Andrea Casalino
 * Created:   22.12.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#pragma once

#include <TrainingTools/interfaces/Trainable.h>
#include <mutex>

namespace train {
class Trainer {
public:
  virtual ~Trainer() = default;

  void train(Trainable &model) {
    std::lock_guard<std::mutex> lock(train_mutex);
    train_(model);
  };

protected:
  virtual void train_(Trainable &model) = 0;

  Trainer() = default;

private:
  std::mutex train_mutex;
};
} // namespace train
