#include <types.h>

#ifndef SQUARE_MATRIX
#define SQUARE_MATRIX

typedef struct SMat
{
	unsigned int size;
	void* data;
	struct FieldInfo* type;
} smat_t;

smat_t* smat(unsigned int size, struct FieldInfo* type, void* data);
smat_t* smatSum(smat_t* a, smat_t* b);
smat_t* smatProduct(smat_t* a, smat_t* b);
smat_t* smatLinearCombination(smat_t* a, unsigned int index, void* alphas, struct FieldInfo* type);

#endif
