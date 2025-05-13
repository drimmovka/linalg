#pragma once

#include <vector>
#include <algorithm>
#include <cmath>

#include "linalg_types.hpp"
#include "linalg_error.hpp"

namespace linalg
{

class Vector {

public:

    explicit Vector(int size=0, Scalar scalar=Scalar());
    
    explicit Vector(const std::vector<Scalar>& vector);

    ~Vector();

    int size() const;

    long double normL2() const;

    Scalar normMax() const;

    Scalar normMaxModulo() const;


// accessing an element by index
    Scalar& operator()(int _i);

    Scalar operator()(int _i) const;

// adding/subtracting vectors
    Vector& operator+=(const Vector& rhs);

    Vector& operator-=(const Vector& rhs);

    friend Vector operator+(Vector lhs, const Vector& rhs);

    friend Vector operator-(Vector lhs, const Vector& rhs);

    
// multiplication by a scalar
    Vector& operator*=(Scalar scalar);

    // scalar * vector
    friend Vector operator*(Vector lhs, Scalar rhs);

    // vector * scalar
    friend Vector operator*(Scalar lhs, Vector rhs);

    
    // dot product
    friend Scalar operator*(Vector lhs, const Vector& rhs);

    // сross product
    friend Scalar operator^(Vector lhs, const Vector& rhs); // not implemented

private:
    std::vector<Scalar> _v;

};


} // namespace linalg
