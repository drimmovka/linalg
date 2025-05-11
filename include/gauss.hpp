#pragma once

#include "matrix.hpp"
#include "vector.hpp"
#include "utils.hpp"
#include "linalg_error.hpp"

namespace linalg
{

class Gauss {
public:

    Gauss();
    ~Gauss();

    Vector solve(const Matrix& A, const Vector& b) const;

private:
    void forwardElimination(Matrix& AM) const;

    int findPivotRow(const Matrix& AM, int _k) const;

    void eliminateRow(Matrix& AM, int _i, int _k) const;
    
    Vector backSubstitution(const Matrix& AM) const;

};

} // namespace linalg