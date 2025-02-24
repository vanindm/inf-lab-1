#include <types.h>

#ifndef MATRIX
#define MATRIX

typedef struct Matrix
{
	unsigned int n;
	unsigned int m;
	void* data;
	struct FieldInfo* type;
} matrix_t;

matrix_t* matrix(unsigned int n, unsigned int m, struct FieldInfo* type, void* data);
matrix_t* matrixSum(matrix_t* a, matrix_t* b);
matrix_t* matrixProduct(matrix_t* a, matrix_t* b);
matrix_t* matrixLinearCombination(matrix_t* a, unsigned int index, void* alphas, struct FieldInfo* type);

#endif
