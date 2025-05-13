#include "jacobi.hpp"

namespace linalg
{

Jacobi::Jacobi() = default;
Jacobi::~Jacobi() = default;

// use only for diagonally Dominant A
Vector Jacobi::solve(const Matrix& A, const Vector& b, int max_iter_count, long double eps) const {
    if (max_iter_count < 0) {
        throw LinalgError("Max iteration count must be non-negative");
    }
    if (eps <= 0) {
        throw LinalgError("Epsilon must be positive");
    }

    auto [jacobi_matrix, jacobi_b] = setup(A, b);
    
    Vector cur_approach = jacobi_b;
    Vector prev_approach = cur_approach;

    int iter_count = 0;
    while (iter_count < max_iter_count) {
        for (int i = 0; i < jacobi_matrix.rows(); ++i) {
            Scalar sigma = 0;
            for (int j = 0; j < jacobi_matrix.cols(); ++j) {
                sigma += jacobi_matrix(i, j) * prev_approach(j);
            }
            cur_approach(i) = jacobi_b(i) + sigma;
        }
        ++iter_count;
        if ( (cur_approach - prev_approach).normMaxModulo() < eps ) {
            break;
        }
        prev_approach = cur_approach;
    }
    return cur_approach;
}


std::pair<Matrix, Vector> Jacobi::setup(const Matrix& A, const Vector& b) const {
    Matrix jacobi_matrix(A.rows(), A.cols());
    Vector jacobi_b(b.size());

    for (int i = 0; i < A.rows(); ++i) {
        if (A(i, i) == 0) {
            throw LinalgError("Singular matrix");
        }
        for (int j = 0; j < A.cols(); ++j) {
            if (i != j) {
                jacobi_matrix(i, j) = -A(i, j) / A(i, i);
            }
        }
    }

    for (int i = 0; i < b.size(); ++i) {
        jacobi_b(i) = b(i) / A(i, i);
    }

    return std::make_pair(jacobi_matrix, jacobi_b);
}

} // namespace linalg