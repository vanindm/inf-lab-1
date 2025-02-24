#include <types.h>
#include <matrix.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

matrix_t* matrix(unsigned int n, unsigned int m, struct FieldInfo* type, void* data)
{
	matrix_t* new = malloc(sizeof(matrix_t));
	if (!new)
	{
		fprintf(stderr, "Ошибка выделения памяти: %lu байт не было выделено.\n", sizeof(matrix_t));
		exit(1);
	}
	new->n = n;
	new->m = m;
	new->type = type;
	new->data = data;
	return new;
}

matrix_t* matrixSum(matrix_t* a, matrix_t* b)
{
	if (a->n != b->n)
	{
		fprintf(stderr, "Логическая ошибка: размеры матриц не совпадают.\n");
		exit(1);
	}
	matrix_t* new = malloc(sizeof(matrix_t));
	if (!new)
	{
		fprintf(stderr, "Ошибка выделения памяти: %lu байт не было выделено.\n", sizeof(matrix_t));
		exit(1);
	}
	new->n = a->n;
	new->m = a->m;
	new->type = a->type;
	new->data = malloc(a->type->size * a->n * a->m);
	if (!new->data)
	{
		fprintf(stderr, "Ошибка выделения памяти: %lu байт не было выделено.\n", a->type->size * a->n * a->m);
		exit(1);
	}
	for (unsigned int i = 0; i < new->n; ++i)
	{
		for (unsigned int j = 0; j < new->m; ++j)
		{
			void* new_element = malloc(a->type->size);
			if (!new_element)
			{
				fprintf(stderr, "Ошибка выделения памяти: %lu байт не было выделено.\n", a->type->size);
				exit(1);
			}
			new_element = sum(new->type, (void *)((char *)a->data + a->n * a->type->size * i + j * a->type->size), (void *)((char *)a->data + a->n * a->type->size * i + j * a->type->size));
			memcpy((void *)((char *)new->data + new->n * new->type->size * i + j * a->type->size), new_element, a->type->size);
			free(new_element);
		}
	}
}

matrix_t* matrixProduct(matrix_t* a, matrix_t* b)
{

}

matrix_t* matrixLinearCombination(matrix_t* a, unsigned int index, void* alphas, struct FieldInfo* type)
{

}
