#include <TrainingTools/Error.h>

namespace train {
Error::Error(const std::string &what) : std::runtime_error(what) {}
} // namespace train