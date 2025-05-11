#include "utils.hpp"

namespace linalg
{

// for SLE
bool SLEIsValid(const Matrix& A, const Vector& b) {
    int size = A.rows();
    return (isSquare(A) && size == b.size());
}

Matrix augmentedMatrix(const Matrix& A, const Vector& b) {
    auto [rows, cols] = A.shape();
    Matrix AM(rows, cols+1);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            AM(i, j) = A(i, j);
        }
    }
    for (int i = 0; i < rows; ++i) {
        AM(i, cols) = b(i);
    }
    return AM;
}

// for matrix
bool isSquare(const Matrix& m) {
    return (m.rows() == m.cols());
}

// for vector
bool isNull(const Vector& v) {
    for (int i = 0; i < v.size(); ++i) {
        if (v(i) != 0) return false;
    }
    return true;
}


} // namespace linalg