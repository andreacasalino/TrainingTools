/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#include <TrainingTools/ModelAware.h>

namespace train {
void ModelAware::initModel(ParametersAware &model) {
  this->model = &model;
  this->setParameters(this->model->getParameters());
}

void ModelAware::resetModel() { this->model = nullptr; }

void ModelAware::setParameters(const Vect &parameters) {
  lastParameters = std::make_unique<Vect>(this->model->getParameters());
  lastGrad = std::make_unique<Vect>(this->getGradient());
  this->model->setParameters(parameters);
};

Vect ModelAware::getGradient() const {
  if (isMinimizing()) {
    return this->model->getGradient();
  }
  return -this->model->getGradient();
};
} // namespace train
