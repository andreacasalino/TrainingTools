/**
 * Author:    Andrea Casalino
 * Created:   22.12.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#pragma once

#include <Eigen/Core>

namespace train {
using Vect = Eigen::VectorXd;
using Matr = Eigen::MatrixXd;

class ParametersAware {
public:
  virtual ~ParametersAware() = default;

  virtual Vect getParameters() const = 0;
  virtual void setParameters(const Vect &) = 0;

  virtual Vect getGradient() const = 0;

  virtual double getCostFunction() const = 0;

protected:
  ParametersAware() = default;
};
} // namespace train
