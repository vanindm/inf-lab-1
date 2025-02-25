#pragma once
#include <types.h>

#ifndef MATRIX
#define MATRIX

typedef struct Matrix {
    unsigned int m;
    unsigned int n;
    void* data;
    struct FieldInfo* type;
} matrix_t;

matrix_t* matrix(unsigned int m, unsigned int n, struct FieldInfo* type, void* data);
void matrixFree(matrix_t* a);
void matrixTranspose(matrix_t* a);
void* matrixGetElement(matrix_t* a, unsigned int i, unsigned int j);
void matrixSetElement(matrix_t* a, unsigned int i, unsigned int j, void* new_value);
matrix_t* matrixSum(matrix_t* a, matrix_t* b);
matrix_t* matrixProduct(matrix_t* a, matrix_t* b);
matrix_t* matrixLinearCombination(matrix_t* a, unsigned int index, void* alphas, struct FieldInfo* type);

#endif
