/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#pragma once

#include <TrainingTools/ModelAware.h>
#include <TrainingTools/iterative/SearchDirectionAware.h>

namespace train {
class LineSearcher : public virtual ModelAware,
                     public virtual SearchDirectionAware {
protected:
  virtual void optimize() = 0;
};
} // namespace train
