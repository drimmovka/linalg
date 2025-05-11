#include "gauss.hpp"

namespace linalg
{

Gauss::Gauss() = default;
Gauss::~Gauss() = default;

Vector Gauss::solve(const Matrix& A, const Vector& b) const {
    if (!SLEIsValid(A, b)) {
        throw LinalgError("SLE is invalid");
    }

    Matrix AM = augmentedMatrix(A, b);
    Gauss::forwardElimination(AM);
    return Gauss::backSubstitution(AM);
}

void Gauss::forwardElimination(Matrix& AM) const {
    for (int k = 0; k < AM.rows(); ++k) {
        AM.swapRows(k, findPivotRow(AM, k));


        if (AM(k, k) == 0) {
            throw LinalgError("Singular matrix");
        }
        
        for (int i = k+1; i < AM.rows(); ++i) {
            eliminateRow(AM, i, k);
        }
    }
}

int Gauss::findPivotRow(const Matrix& AM, int _k) const {
    int pivot = _k;
    
    for (int i = _k; i < AM.rows(); ++i) {
        if (abs(AM(i, _k)) > abs(AM(pivot, _k))) {
            pivot = i;
        }
    }
    
    return pivot;
}

void Gauss::eliminateRow(Matrix& AM, int _i, int _k) const {
    Scalar coef = -AM(_i, _k) / AM(_k, _k);

    AM.addRow(_k, _i, coef);

    if ( isNull(AM.row(_i)) ) {
        throw LinalgError("Singular matrix");
    }
}

Vector Gauss::backSubstitution(const Matrix& AM) const {
    Vector x(AM.rows());

    for (int k = AM.rows()-1; k >= 0; --k) {
        x(k) = AM(k, AM.cols()-1);

        for (int j = AM.cols()-2; j >= k+1; --j) {
            x(k) -= AM(k, j) * x(j);
        }
        
        x(k) /= AM(k, k);
    }

    return x;
}


} // namespace linalg