#pragma once

#include <vector>
#include <cmath>

#include "linalg_types.hpp"
#include "linalg_error.hpp"
#include "vector.hpp"

namespace linalg
{

class Matrix {
// agreement: guaranteed that initialized matrix is NOT jagged
public:
    explicit Matrix(int rows, int cols, Scalar scalar=Scalar());

    explicit Matrix(const std::vector<std::vector<Scalar>>& matrix);

    ~Matrix();
    
    int rows() const;

    int cols() const;

    std::pair<int, int> shape() const;

// accessing an element by index
    Scalar& operator()(int _i, int _j);

    Scalar operator()(int _i, int _j) const;

// taking a row/column
    Vector row(int _i) const;

    Vector col(int _j) const;

// adding/subtracting matrix
    Matrix& operator+=(const Matrix& rhs);

    Matrix& operator-=(const Matrix& rhs);

    friend Matrix operator+(Matrix lhs, const Matrix& rhs);

    friend Matrix operator-(Matrix lhs, const Matrix& rhs);

// multiplication by a scalar
    Matrix& operator*=(Scalar scalar);

    // scalar * matrix
    friend Matrix operator*(Matrix lhs, Scalar rhs);

    // matrix * scalar
    friend Matrix operator*(Scalar lhs, Matrix rhs);

// matrix multiplication
    friend Matrix operator*(Matrix lhs, const Matrix& rhs);


// elementary transformations
    void swapRows(int _i1, int _i2);

    void swapCols(int _j1, int _j2);

    void multiplyRow(int _i, Scalar scalar);

    void multiplyCol(int _j, Scalar scalar);

    void addRow(int src_i, int dst_i, Scalar scalar);

    void addCol(int src_j, int dst_j, Scalar scalar);

// other operations
    int rank() const; // not implemented

    void transpose(); // not implemented

    Scalar det() const; // not implemented

    Scalar minor(int i, int j) const; // not implemented

private:
    std::vector<std::vector<Scalar>> _m;
};

} // namespace linalg