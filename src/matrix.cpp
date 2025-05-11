#include "matrix.hpp"

namespace linalg
{

Matrix::Matrix(int rows, int cols, Scalar scalar) {
    if (rows < 0 || cols < 0) {
        throw LinalgError("Invalid shape");
    }
    _m.assign(rows, std::vector(cols, scalar));
}

Matrix::Matrix(const std::vector<std::vector<Scalar>>& matrix) {
    int cols = (matrix.empty() ? 0 : matrix[0].size());

    for (auto& row : matrix) {
        if (row.size() != cols) {
            throw LinalgError("Matrix is jagged");
        }
    }

    _m = matrix;
}

Matrix::~Matrix() = default;

int Matrix::rows() const {
    return _m.size();
}

int Matrix::cols() const {
    return (_m.empty() ? 0 : _m[0].size()); 
}

std::pair<int, int> Matrix::shape() const {
    return std::make_pair(rows(), cols());
}

// accessing an element by index
Scalar& Matrix::operator()(int _i, int _j) {
    return _m[_i][_j];
}

Scalar Matrix::operator()(int _i, int _j) const {
    return _m[_i][_j];
}

// taking a row/column
Vector Matrix::row(int _i) const {
    return Vector(_m[_i]);
}

Vector Matrix::col(int _j) const {
    std::vector<Scalar> col(rows());
    for (int i = 0; i < rows(); ++i) {
        col[i] = _m[i][_j];
    }
    return Vector(col);
}

// adding/subtracting matrix
Matrix& Matrix::operator+=(const Matrix& rhs) {
    if (shape() != rhs.shape()) {
        throw LinalgError("Dimension mismatch");
    }
    for (int i = 0; i < rows(); ++i) {
        for (int j = 0; j < cols(); ++j) {
            _m[i][j] += rhs._m[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& rhs) {
    if (shape() != rhs.shape()) {
        throw LinalgError("Dimension mismatch");
    }
    for (int i = 0; i < rows(); ++i) {
        for (int j = 0; j < cols(); ++j) {
            _m[i][j] -= rhs._m[i][j];
        }
    }
    return *this;
}

Matrix operator+(Matrix lhs, const Matrix& rhs) {
    lhs += rhs;
    return lhs;
}

Matrix operator-(Matrix lhs, const Matrix& rhs) {
    lhs -= rhs;
    return lhs;
}

// multiplication by a scalar
Matrix& Matrix::operator*=(Scalar scalar) {
    for (int i = 0; i < rows(); ++i) {
        for (int j = 0; j < cols(); ++j) {
            _m[i][j] *= scalar;
        }
    }
    return *this;
}

// scalar * matrix
Matrix operator*(Matrix lhs, Scalar rhs) {
    lhs *= rhs;
    return lhs;
}

// matrix * scalar
Matrix operator*(Scalar lhs, Matrix rhs) {
    return rhs * lhs;
}

// matrix multiplication
Matrix operator*(Matrix lhs, const Matrix& rhs) {
    std::abort();
    // TODO: implement
}


// elementary transformations
void Matrix::swapRows(int _i1, int _i2) {
    std::swap(_m[_i1], _m[_i2]);
}

void Matrix::swapCols(int _j1, int _j2) {
    for (int i = 0; i < rows(); ++i) {
        std::swap(_m[i][_j1], _m[i][_j2]);
    }
}

void Matrix::multiplyRow(int _i, Scalar scalar) {
    for (int j = 0; j < cols(); ++j) {
        _m[_i][j] *= scalar;
    }
}

void Matrix::multiplyCol(int _j, Scalar scalar) {
    for (int i = 0; i < rows(); ++i) {
        _m[i][_j] *= scalar;
    }
}

void Matrix::addRow(int src_i, int dst_i, Scalar scalar) {
    for (int j = 0; j < cols(); ++j) {
        _m[dst_i][j] += scalar * _m[src_i][j];
    }
}

void Matrix::addCol(int src_j, int dst_j, Scalar scalar) {
    for (int i = 0; i < rows(); ++i) {
        _m[i][dst_j] += scalar * _m[i][src_j];
    }
}

// other operations
int Matrix::rank() const {
    std::abort();
    // TODO: implement
} 

void Matrix::transpose() {
    std::abort();
    // TODO: implement
}

Scalar Matrix::det() const {
    std::abort();
    // TODO: implement
}

Scalar Matrix::minor(int i, int j) const {
    std::abort();
    // TODO: implement
}

} // namespace linalg