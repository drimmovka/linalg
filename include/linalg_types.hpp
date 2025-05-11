#pragma once

#include <vector>
#include <utility>
#include <random>

namespace linalg
{
    using LinalgRandomEngine = std::mt19937;
    using Scalar = long double;
    using Interval = std::pair<Scalar, Scalar>;
} // namespace linalg