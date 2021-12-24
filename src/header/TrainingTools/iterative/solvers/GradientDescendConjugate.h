/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#pragma once

#include <TrainingTools/iterative/IterativeTrainer.h>
#include <TrainingTools/iterative/direction_optimizer/FixedStep.h>
#include <TrainingTools/iterative/direction_optimizer/YundaSearcher.h>

namespace train {
/**
 * @brief refer to <a href="linkURL">
 * https://www.caam.rice.edu/~zhang/caam454/pdf/cgsurvey.pdf </a> and the
 * possible strategies to compute beta
 */
class BetaStrategy : virtual public ModelAware,
                     virtual public SearchDirectionAware {
protected:
  virtual float getBeta() const = 0;
};

class FletcherReeves : public BetaStrategy {
protected:
  float getBeta() const override;
};

class PolakRibiere : public BetaStrategy {
protected:
  float getBeta() const override;
};

class HestenesStiefel : public BetaStrategy {
protected:
  float getBeta() const override;
};

class DaiYuan : public BetaStrategy {
protected:
  float getBeta() const override;
};

/**
 * @brief At every iteration the minimum along the direction of the conjugate
 * gradient method, <a href="linkURL">
 * https://www.caam.rice.edu/~zhang/caam454/pdf/cgsurvey.pdf </a> , is searched
 */
template <typename LineSearcherT = YundaSearcher,
          typename BetaStrategyT = FletcherReeves>
class GradientDescendConjugate : public IterativeTrainer,
                                 public LineSearcherT,
                                 public BetaStrategyT {
  static_assert(std::is_base_of<LineSearcher, LineSearcherT>::value,
                "LineSearcherT should be a form of LineSearcher");
  static_assert(std::is_base_of<BetaStrategy, BetaStrategyT>::value,
                "BetaStrategyT should be a form of BetaStrategy");

protected:
  void updateDirection() override {
    Vect direction = this->getGradient();
    direction *= -1.0;
    Vect correction = getGradient();
    correction *= this->getBeta();
    direction += correction;
    setDirection(direction);
  };
  void initDirection() override { setDirection(getGradient()); };
};

using GradientDescendConjugateFixed = GradientDescendConjugate<FixedStep>;
} // namespace train
