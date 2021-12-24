/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#pragma once

#include <TrainingTools/iterative/direction_optimizer/LineSearcher.h>

namespace train {
class FixedStep : public virtual ModelAware, public virtual LineSearcher {
public:
  void setOptimizationStep(const double step);

protected:
  void optimize() override;

private:
  double step = 0.1;
};
} // namespace train
