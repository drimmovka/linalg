#include "vector.hpp"

namespace linalg
{

Vector::Vector(int size, Scalar scalar) {
    if (size < 0) {
        throw LinalgError("Invalid shape");
    }
    _v.assign(size, scalar);
}

Vector::Vector(const std::vector<Scalar>& vector)
    : _v(vector)
{}

Vector::~Vector() = default;

int Vector::size() const {
    return _v.size();
}

// L2 norm
long double Vector::norm() const {
    long double sum = 0;
    for (int i = 0; i < size(); ++i) {
        sum += _v[i];
    }
    return sqrt(sum);
}

// accessing an element by index
Scalar& Vector::operator()(int _i) {
    return _v[_i];
}

Scalar Vector::operator()(int _i) const {
    return _v[_i];
}

// adding/subtracting vectors
Vector& Vector::operator+=(const Vector& rhs) {
    if (size() != rhs.size()) {
        throw LinalgError("Dimension mismatch");
    }
    for (int i = 0; i < size(); ++i) {
        _v[i] += rhs._v[i];
    }
    return *this;
}

Vector& Vector::operator-=(const Vector& rhs) {
    if (size() != rhs.size()) {
        throw LinalgError("Dimension mismatch");
    }
    for (int i = 0; i < size(); ++i) {
        _v[i] -= rhs._v[i];
    }
    return *this;
}

Vector operator+(Vector lhs, const Vector& rhs) {
    lhs += rhs;
    return lhs;
}

Vector operator-(Vector lhs, const Vector& rhs) {
    lhs -= rhs;
    return lhs;
}


// multiplication by a scalar
Vector& Vector::operator*=(Scalar scalar) {
    for (int i = 0; i < size(); ++i) {
        _v[i] *= scalar;
    }
    return *this;
}

// scalar * vector
Vector operator*(Vector lhs, Scalar rhs) {
    lhs *= rhs;
    return lhs;
}

// vector * scalar
Vector operator*(Scalar lhs, Vector rhs) {
    return rhs * lhs;
}

// dot product
Scalar operator*(Vector lhs, const Vector& rhs) {
    if (lhs.size() != rhs.size()) {
        throw LinalgError("Dimension mismatch");
    }
    Scalar product = 0;
    for (int i = 0; i < lhs.size(); ++i) {
        product += lhs._v[i] * rhs._v[i];
    }
    return product;
}

// сross product
Scalar operator^(Vector lhs, const Vector& rhs) {
    std::abort();
    // TODO: implement
}


} // namespace linalg
