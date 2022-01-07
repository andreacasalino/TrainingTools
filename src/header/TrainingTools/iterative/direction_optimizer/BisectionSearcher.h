/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#pragma once

#include <TrainingTools/iterative/direction_optimizer/LineSearcher.h>

namespace train {
class BisectionSearcher : public virtual LineSearcher {
public:
  void setBisectionTrials(const std::size_t trials);

protected:
  void optimize() override;

private:
  std::size_t bisection_trials = 10;
};
} // namespace train
