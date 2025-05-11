#include "vector_generator.hpp"

namespace linalg
{

VectorGenerator::VectorGenerator()
    : _rd()
    , _gen(_rd())
    , _dis()
{}

VectorGenerator::~VectorGenerator() = default;

Vector VectorGenerator::random(int size, const Interval& interval) {
    setDistribution(interval);
    
    Vector v(size);
    for (int i = 0; i < size; ++i) {
        v(i) = _dis(_gen);
    }
    return v;
}

void VectorGenerator::setDistribution(const Interval& interval) {
    _dis = std::uniform_real_distribution<> (
        std::min(interval.first, interval.second),
        std::max(interval.first, interval.second)
    );
}

} // namespace linalg