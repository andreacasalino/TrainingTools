/**
 * Author:    Andrea Casalino
 * Created:   04.06.2021
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#pragma once

namespace train {
class MinimizeOrMaximizeAware {
public:
  virtual ~MinimizeOrMaximizeAware() = default;

  bool isMinimizing() const { return min_or_max; }
  void minimize() { min_or_max = true; }

  bool isMaximizing() const { return !min_or_max; }
  void maximize() { min_or_max = false; }

protected:
  MinimizeOrMaximizeAware() = default;

private:
  bool min_or_max = true;
};
} // namespace train
