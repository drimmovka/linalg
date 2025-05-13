#pragma once

#include <utility>

#include "linalg_types.hpp"
#include "linalg_error.hpp"
#include "matrix_generator.hpp"
#include "vector_generator.hpp"

namespace linalg
{

class SLEGenerator {
public:
    SLEGenerator();
    ~SLEGenerator();

    std::pair<Matrix, Vector> random(int size, const Interval& A_interval, const Interval& b_interval);
    
    std::pair<Matrix, Vector> randomDiagonallyDominant(int size, const Interval& A_interval, const Interval& b_interval);
    
    std::pair<Matrix, Vector> hilbert(int size, const Interval& b_interval);

private:
    MatrixGenerator _mg;
    VectorGenerator _vg;
};

} // namespace linalg