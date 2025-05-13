#pragma once

// only the functions necessary for the application CalcSLE are implemented
// no memory clean up provided! (will be fixed soon)

#ifdef __cplusplus
extern "C" {
#endif

struct SLE {
    int size;
    long double **raw_A;
    long double *raw_b;
};

struct SLE *genRandomSLE(int size, long double A_inter_left, long double A_inter_right, long double b_inter_left, long double b_inter_right);

struct SLE *genRandomDiagonallyDominantSLE(int size, long double A_inter_left, long double A_inter_right, long double b_inter_left, long double b_inter_right);
    
struct SLE *genHilbertSLE(int size, long double b_inter_left, long double b_inter_right);

long double *gauss(int size, long double **raw_A, long double* raw_b);

long double *jacobi(int size, long double **raw_A, long double* raw_b, int max_iter_count=1000, long double eps=1e-6);

#ifdef __cplusplus
}
#endif // extern "C"