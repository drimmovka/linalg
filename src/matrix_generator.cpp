#include "matrix_generator.hpp"

namespace linalg
{

MatrixGenerator::MatrixGenerator()
    : _rd()
    , _gen(_rd())
    , _dis()
{}

MatrixGenerator::~MatrixGenerator() = default;

void MatrixGenerator::setDistribution(const Interval& interval) {
    _dis = std::uniform_real_distribution<> (
        std::min(interval.first, interval.second),
        std::max(interval.first, interval.second)
    );
}

Matrix MatrixGenerator::random(int rows, int cols, const Interval& interval) {
    setDistribution(interval);

    Matrix m(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            m(i, j) = _dis(_gen);
        }
    }
    return m;
}

Matrix MatrixGenerator::hilbert(int size) {
    Matrix m(size, size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            m(i, j) = 1.0 / (i + j + 1);
        }
    }
    return m;
}

Matrix MatrixGenerator::randomDiagonallyDominant(int size, const Interval& interval) {
    setDistribution(interval);

    Matrix m(size, size);
    for (int i = 0; i < size; ++i) {
        Scalar sum = 0.0;
        for (int j = 0; j < size; ++j) {
            if (i != j) {
                m(i, j) = _dis(_gen);
                sum += std::abs(m(i, j));
            }
        }
        m(i, i) = sum + 1.0 + std::abs(_dis(_gen));
    }
    return m;
}

} // namespace linalg