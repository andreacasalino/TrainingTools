/**
 * Author:    Andrea Casalino
 * Created:   22.12.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#pragma once

#include <TrainingTools/interfaces/Trainable.h>

namespace train {
class Trainer {
public:
  virtual ~Trainer() = default;

  virtual void train(Trainable &model) = 0;

protected:
  Trainer() = default;
};
} // namespace train
