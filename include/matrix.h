#pragma once
#include <types.h>
#include <error.h>

#ifndef MATRIX_H_
#define MATRIX_H_

typedef struct Matrix {
    unsigned int m;
    unsigned int n;
    void* data;
    struct FieldInfo* type;
} matrix_t;

matrix_t* matrix(unsigned int m, unsigned int n, struct FieldInfo* type, void* data, error_t** error);
void matrixFree(matrix_t* a);
matrix_t* matrixTranspose(matrix_t* a, error_t** error);
void* matrixGetElement(matrix_t* a, unsigned int i, unsigned int j, error_t** error);
void* matrixSetElement(matrix_t* a, unsigned int i, unsigned int j, void* new_value, error_t** error);
matrix_t* matrixSum(matrix_t* a, matrix_t* b, error_t** error);
matrix_t* matrixProduct(matrix_t* a, matrix_t* b, error_t** error);
matrix_t* matrixLinearCombination(struct FieldInfo* type, matrix_t* a, unsigned int index, void* alphas, error_t** error);

#endif
