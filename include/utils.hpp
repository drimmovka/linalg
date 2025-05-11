#pragma once

#include "matrix.hpp"

namespace linalg
{

// for SLE
bool SLEIsValid(const Matrix& A, const Vector& b);

Matrix augmentedMatrix(const Matrix& A, const Vector& b);

// for matrix
bool isSquare(const Matrix& m);

// for vector
bool isNull(const Vector& v);


} // namespace linalg