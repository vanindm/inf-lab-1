#include <types.h>
#include <string.h>
#include <stdlib.h>
#include <square_mat.h>

smat_t* smat(unsigned int size, struct FieldInfo* type, void* data)
{
	smat_t* new = malloc(sizeof(smat_t));
	new->size = size;
	new->type = type;
	new->data = data;
	return new;
}

smat_t* smatSum(smat_t* a, smat_t* b)
{
	//if (a->size != b->size)
	//if (a->type != b->type)
	smat_t* new = malloc(sizeof(smat_t));
	new->size = a->size;
	new->type = a->type;
	new->data = malloc(a->type->size * a->size * a->size);
	for (unsigned int i = 0; i < new->size; ++i)
	{
		for (unsigned int j = 0; j < new->size; ++j)
		{
			*((void **)new->data + new->size * new->type->size * i + j * a->type->size) = sum(new->type, (a->data + a->size * a->type->size * i + j * a->type->size), (a->data + a->size * a->type->size * i + j * a->type->size));
		}
	}
}

smat_t* smatProduct(smat_t* a, smat_t* b)
{

}

smat_t* smatLinearCombination(smat_t* a, unsigned int index, void* alphas, struct FieldInfo* type)
{

}
