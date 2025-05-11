#include "sle_generator.hpp"

namespace linalg
{

SLEGenerator::SLEGenerator() = default;
SLEGenerator::~SLEGenerator() = default;

std::pair<Matrix, Vector> SLEGenerator::random(int size, const Interval& A_interval, const Interval& b_interval) {
    return std::make_pair( _mg.random(size, size, A_interval), _vg.random(size, b_interval) );
}

std::pair<Matrix, Vector> SLEGenerator::randomDiagonallyDominant(int size, const Interval& A_interval, const Interval& b_interval) {
    return std::make_pair( _mg.randomDiagonallyDominant(size, A_interval), _vg.random(size, b_interval) );
}

std::pair<Matrix, Vector> SLEGenerator::hilbert(int size, const Interval& b_interval) {
    return std::make_pair( _mg.hilbert(size), _vg.random(size, b_interval) );
}


} // namespace linalg