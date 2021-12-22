/**
 * Author:    Andrea Casalino
 * Created:   01.01.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#pragma once

#include <stdexcept>

namespace train {
class Error : public std::runtime_error {
public:
  explicit Error(const std::string &what);
};
} // namespace train
