/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#pragma once

#include <TrainingTools/ModelAware.h>
#include <TrainingTools/Trainer.h>
#include <TrainingTools/iterative/IterationsAware.h>
#include <TrainingTools/iterative/direction_optimizer/LineSearcher.h>
#include <chrono>

namespace train {
/**
 * @brief Base class for every iterative trainer.
 * The iterations are stopped in case:
    - the l1 norm of the gradient is below a certain threshold
    - the l1 norm of the difference between the old values of the parameters and
 the new ones is below a certain threshold
 */
class IterativeTrainer : public Trainer,
                         public virtual ModelAware,
                         public virtual IterationsAware,
                         public virtual LineSearcher {
public:
  void train_(ParametersAware &model) override;

  /**
   * @brief Set the threshold to consider for the parameters improvement
   * in order to decide whether to arrest the iterations or not.
   * @param the minimum l1 norm acceptable value
   * @throw when the passed value is negative
   */
  void setParametersTollerance(const double value);
  /**
   * @brief Set the threshold to consider for the gradient
   * in order to decide whether to arrest the iterations or not.
   * @param the minimum l1 norm acceptable value
   * @throw when the passed value is negative
   */
  void setGradientTollerance(const double value);

  /**
   * @brief Display in the console the advancement.
   *  By default the advancement is not displayed
   */
  inline void enablePrintAdvancement() { this->printAdvnc = true; };
  /**
   * @brief Prevent to display in the console the advancement
   *  By default the advancement is not displayed
   */
  inline void disablePrintAdvancement() { this->printAdvnc = false; };

  /**
   * @return the time elapsed in the previous call to train(...)
   */
  inline const std::chrono::milliseconds &getElapsedTime() const {
    return this->elapsed;
  };

private:
  double parametersTollerance = 0.005;
  double gradientTollerance = 0.005;
  bool printAdvnc = false;
  std::chrono::milliseconds elapsed = std::chrono::milliseconds(0);
};
} // namespace train
