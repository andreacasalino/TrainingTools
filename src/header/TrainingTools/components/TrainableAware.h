/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#pragma once

#include <TrainingTools/components/Trainable.h>

namespace train {
class ModelAware {
protected:
  virtual Trainable &getModel() = 0;
  virtual const Trainable &getModel() const = 0;
};
} // namespace train
