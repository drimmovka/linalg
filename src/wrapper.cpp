#include "wrapper.h"
#include "linalg.hpp"

extern "C" {
    long double *gauss(int size, long double **raw_A, long double* raw_b) {
        std::vector<std::vector<linalg::Scalar>> stl_A(size, std::vector<linalg::Scalar>(size));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                stl_A[i][j] = raw_A[i][j];
            }
        }
        linalg::Matrix A(stl_A);

        std::vector<linalg::Scalar> stl_b(size);
        for (int i = 0; i < size; ++i) {
            stl_b[i] = raw_b[i];
        }
        linalg::Vector b(stl_b);


        linalg::Gauss gauss;
        auto x = gauss.solve(A, b);

        long double *raw_x = new long double[size];
        for (int i = 0; i < size; ++i) {
            raw_x[i] = x(i);
        }
        return raw_x;
    }

    long double *randomVector(int size, long double inter_left, long double inter_right) {
        long double *raw_vector = new long double[size];
        
        linalg::VectorGenerator vg;
        linalg::Vector stl_vector = vg.random(size, {inter_left, inter_right});

        for (int i = 0; i < size; ++i) {
            raw_vector[i] = stl_vector(i);
        }

        return raw_vector;
    }

    struct SLE *genRandomSLE(int size, long double inter_left, long double inter_right) {
        linalg::SLEGenerator sleg;
        auto [A, b] = sleg.random(size, {inter_left, inter_right}, {inter_left, inter_right});

        SLE *sle = new SLE();
        sle->raw_A = new long double*[size];
        for (int i = 0; i < size; ++i) {
            sle->raw_A[i] = new long double[size];
        }
        sle->raw_b = new long double[size];

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                sle->raw_A[i][j] = A(i, j);
            }
        }
        for (int i = 0; i < size; ++i) {
            sle->raw_b[i] = b(i);
        }
        
        return sle;
    }

}