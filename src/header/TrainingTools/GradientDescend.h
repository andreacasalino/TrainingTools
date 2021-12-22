/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#pragma once

#include <TrainingTools/components/IterativeDescend.h>
#include <TrainingTools/strategies/YundaSearcher.h>

namespace train {
/**
 * @brief At every iteration the minimum along the gradient direction is
 * searched
 */
template <typename LineSearcherT = YundaSearcher>
class GradientDescend : public IterativeDescend,
                        public TrainSetT,
                        public LineSearcherT {
  static_assert(std::is_base_of<LineSearcher, LineSearcherT>::value,
                "LineSearcherT should be a form of LineSearcher");

protected:
  inline void descend() override {
    Vect direction = this->getGradient();
    direction *= -1.f;
    this->minimize(direction);
  };
};
} // namespace train
