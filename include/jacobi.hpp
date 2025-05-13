#pragma once

#include "matrix.hpp"
#include "vector.hpp"
#include "utils.hpp"
#include "linalg_error.hpp"

namespace linalg
{

class Jacobi {
public:
    Jacobi();
    ~Jacobi();
    
    Vector solve(const Matrix& A, const Vector& b, int max_iter_count=1000, long double eps=1e-6) const;

private:

    std::pair<Matrix, Vector> setup(const Matrix& A, const Vector& b) const;
};

} // namespace linalg