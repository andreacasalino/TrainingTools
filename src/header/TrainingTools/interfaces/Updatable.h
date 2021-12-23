/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#pragma once

namespace train {
/**
 * @brief an object that is updated at every iteration
 */
class Updatable {
public:
  virtual ~Updatable() = default;

protected:
  Updatable() = default;

  /**
   * @brief called at every iteration
   */
  virtual void update() = 0;
  /**
   * @brief called before starting a new training process to clean up
   */
  virtual void reset() = 0;
};
} // namespace train
