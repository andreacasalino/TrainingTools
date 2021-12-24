/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#pragma once

#include <TrainingTools/interfaces/ParametersAware.h>
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
    last_direction = std::move(direction);
    direction = std::make_unique<Vect>(dir);
  };

  const Vect &getDirection() const { return *direction; };
  const Vect &getLastDirection() const { return *last_direction; };

private:
  std::unique_ptr<Vect> direction;
  std::unique_ptr<Vect> last_direction;
};
} // namespace train
