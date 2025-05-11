#pragma once

#include <random>

#include "matrix.hpp"
#include "linalg_types.hpp"
#include "linalg_error.hpp"

namespace linalg
{

class MatrixGenerator {
public:

    MatrixGenerator();
    ~MatrixGenerator();


    Matrix random(int rows, int cols, const Interval& interval={0, 0});
    
    Matrix randomDiagonallyDominant(int size, const Interval& interval={0, 0});
    
    Matrix hilbert(int size);

private:
    std::random_device _rd;
    LinalgRandomEngine _gen;
    std::uniform_real_distribution<> _dis;

private:
    void setDistribution(const Interval& interval);

    
};

} // namespace linalg