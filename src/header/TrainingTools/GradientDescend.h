/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#pragma once

#include <TrainingTools/bases/IterativeTrainer.h>
#include <TrainingTools/strategies/YundaSearcher.h>

namespace train {
/**
 * @brief At every iteration the minimum along the gradient direction is
 * searched
 */
template <typename LineSearcherT = YundaSearcher>
class GradientDescend : public IterativeTrainer, public LineSearcherT {
  static_assert(std::is_base_of<LineSearcher, LineSearcherT>::value,
                "LineSearcherT should be a form of LineSearcher");

protected:
  void updateDirection() override { setDirection(getGradient()); };
  void initDirection() override { updateDirection(); };
  Vect descend() override { return this->optimize(getDirection()); };
};
} // namespace train
