/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#pragma once

#include <TrainingTools/bases/ModelAware.h>
#include <TrainingTools/interfaces/SearchDirectionAware.h>

namespace train {
class LineSearcher : public virtual ModelAware,
                     public virtual SearchDirectionAware {
protected:
  /**
   * @brief finds the values of the weight maximizing the likelihood, along the
   * passed direction
   * @param the direction along which to search the optimum
   */
  virtual void optimize() = 0;
};
} // namespace train
