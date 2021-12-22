/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#pragma once

#include <cstdlib>

namespace train {
class IterationsAware {
public:
  virtual ~IterationsAware() = default;

  /**
   * @param the maximum number of iterations allowed to search the optimum
   * @throw in case the passed number of interations is too low
   */
  void setMaxIterations(const std::size_t iter);

  std::size_t getIterations() const { return doneIterations; };
  void resetIterations() { doneIterations = 1; };

protected:
  IterationsAware() = default;

private:
  std::size_t maxIterations = 100;
  std::size_t doneIterations = 1;
};
} // namespace train
