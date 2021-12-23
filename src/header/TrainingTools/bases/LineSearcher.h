/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#pragma once

#include <TrainingTools/bases/ModelAware.h>

namespace train {
class LineSearcher : public virtual ModelAware {
protected:
  /**
   * @brief finds the values of the weight maximizing the likelihood, along the
   * passed direction
   * @param the direction along which to search the optimum
   */
  virtual Vect optimize(const Vect &direction) = 0;
};
} // namespace train
