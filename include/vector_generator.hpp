#pragma once

#include <random>

#include "linalg_types.hpp"
#include "linalg_error.hpp"
#include "vector.hpp"

namespace linalg
{

class VectorGenerator {
public:

    VectorGenerator();
    ~VectorGenerator();

    Vector random(int size, const Interval& interval);

private:
    std::random_device _rd;
    LinalgRandomEngine _gen;
    std::uniform_real_distribution<> _dis;

private:
    void setDistribution(const Interval& interval);
};

} // namespace linalg