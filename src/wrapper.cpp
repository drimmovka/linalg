#include "wrapper.h"
#include "linalg.hpp"

extern "C" {

    struct SLE *genRandomSLE(int size, long double A_inter_left, long double A_inter_right, long double b_inter_left, long double b_inter_right) {
        linalg::SLEGenerator sleg;
        auto [A, b] = sleg.randomDiagonallyDominant(size, {A_inter_left, A_inter_right}, {b_inter_left, b_inter_right});

        SLE *sle = new SLE();

        sle->size = size;

        sle->raw_A = new long double*[size];
        for (int i = 0; i < size; ++i) {
            sle->raw_A[i] = new long double[size];
        }
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                sle->raw_A[i][j] = A(i, j);
            }
        }

        sle->raw_b = new long double[size];
        for (int i = 0; i < size; ++i) {
            sle->raw_b[i] = b(i);
        }
        
        return sle;
    }

    struct SLE *genRandomDiagonallyDominantSLE(int size, long double A_inter_left, long double A_inter_right, long double b_inter_left, long double b_inter_right) {
        linalg::SLEGenerator sleg;
        auto [A, b] = sleg.randomDiagonallyDominant(size, {A_inter_left, A_inter_right}, {b_inter_left, b_inter_right});

        SLE *sle = new SLE();
        
        sle->size = size;

        sle->raw_A = new long double*[size];
        for (int i = 0; i < size; ++i) {
            sle->raw_A[i] = new long double[size];
        }
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                sle->raw_A[i][j] = A(i, j);
            }
        }

        sle->raw_b = new long double[size];
        for (int i = 0; i < size; ++i) {
            sle->raw_b[i] = b(i);
        }
        
        return sle;
    }
    
    struct SLE *genHilbertSLE(int size, long double b_inter_left, long double b_inter_right) {
        linalg::SLEGenerator sleg;
        auto [A, b] = sleg.hilbert(size, {b_inter_left, b_inter_right});

        SLE *sle = new SLE();
        
        sle->size = size;

        sle->raw_A = new long double*[size];
        for (int i = 0; i < size; ++i) {
            sle->raw_A[i] = new long double[size];
        }
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                sle->raw_A[i][j] = A(i, j);
            }
        }

        sle->raw_b = new long double[size];
        for (int i = 0; i < size; ++i) {
            sle->raw_b[i] = b(i);
        }
        
        return sle;
    }

    long double *gauss(int size, long double **raw_A, long double* raw_b) {
        linalg::Matrix A(size, size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                A(i, j) = raw_A[i][j];
            }
        }

        linalg::Vector b(size);
        for (int i = 0; i < size; ++i) {
            b(i) = raw_b[i];
        }

        linalg::Gauss gauss;
        auto x = gauss.solve(A, b);

        long double *raw_x = new long double[size];
        for (int i = 0; i < size; ++i) {
            raw_x[i] = x(i);
        }
        return raw_x;
    }

    long double *jacobi(int size, long double **raw_A, long double* raw_b, int max_iter_count, long double eps) {
        linalg::Matrix A(size, size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                A(i, j) = raw_A[i][j];
            }
        }

        linalg::Vector b(size);
        for (int i = 0; i < size; ++i) {
            b(i) = raw_b[i];
        }

        linalg::Jacobi jacobi;
        auto x = jacobi.solve(A, b, max_iter_count, eps);

        long double *raw_x = new long double[size];
        for (int i = 0; i < size; ++i) {
            raw_x[i] = x(i);
        }
        return raw_x;
    }
    
} // extern "C"