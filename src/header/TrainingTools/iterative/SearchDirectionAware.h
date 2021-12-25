/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#pragma once

#include <TrainingTools/ParametersAware.h>
#include <memory>

namespace train {
class SearchDirectionAware {
public:
  ~SearchDirectionAware() = default;

protected:
  SearchDirectionAware() = default;

  virtual void initDirection() = 0;
  virtual void updateDirection() = 0;

  void setDirection(const Vect &dir) {
    direction = std::make_unique<Vect>(dir);
  };

  const Vect &getDirection() const { return *direction; };

private:
  std::unique_ptr<Vect> direction;
};
} // namespace train
