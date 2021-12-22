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

class Trainable {
public:
  virtual ~Trainable() = default;

  virtual Vect getParameters() = 0;

  virtual Vect getGradient() = 0;

  virtual double getCostFunction() = 0;

protected:
  Trainable() = default;
};
} // namespace train
