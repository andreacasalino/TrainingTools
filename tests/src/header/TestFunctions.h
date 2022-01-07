#pragma once

#include <EasyTestFunction.h>
#include <MediumTestFunction.h>

namespace train::test {
using EasyTestFunction2d = train::test::EasyFunction<2>;
using EasyTestFunction4d = train::test::EasyFunction<4>;

using MediumTestFunction4d = train::test::MediumFunction<4>;
using MediumTestFunction10d = train::test::MediumFunction<10>;
} // namespace train::test
