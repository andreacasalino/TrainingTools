#include <TestFunction.h>

namespace train::test {
Vect TestFunction::getParameters() const { return parameters; };

void TestFunction::setParameters(const Vect &point) { parameters = point; };
} // namespace train::test
