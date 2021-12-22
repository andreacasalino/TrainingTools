/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#pragma once

#include <TrainingTools/components/IterationsAware.h>
#include <TrainingTools/components/LineSearcher.h>

namespace train {
/**
 * @brief The approach described here
 * http://www.optimization-online.org/DB_FILE/2016/07/5560.pdf (Algorithm A) is
 * implemented by this class.
 */
class YundaSearcher : public LineSearcher, virtual public IterationsAware {
protected:
  void minimize(const Vect &direction) override;

  float computeC1() const;
};
} // namespace train
