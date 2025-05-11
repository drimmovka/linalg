#pragma once

// only the functions necessary for the application CalcSLE are implemented

#ifdef __cplusplus
extern "C" {
#endif

struct SLE {
    long double **raw_A;
    long double *raw_b;
};

long double *gauss(int size, long double **raw_A, long double* raw_b);

struct SLE *genRandomSLE(int size, long double inter_left, long double inter_right);

// struct SLE *genRandomDiagonallyDominantSLE(int size, long double inter_left, long double inter_right);
    
// struct SLE *genHilbertSLE(int size);


#ifdef __cplusplus
}
#endif // extern "C"