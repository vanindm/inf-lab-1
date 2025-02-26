#include <matrix.h>
#include <types.h>
#include <error.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

matrix_t* matrix(unsigned int m, unsigned int n, struct FieldInfo* type, void* data, error_t** error)
{
    matrix_t* new = malloc(sizeof(matrix_t));
    if (!new) {
        *error = throwError("невозможно выделить память для matrix_t при создании", getMemoryError(), NULL);
		return NULL;
    }
    new->m = m;
    new->n = n;
    new->type = type;
    new->data = malloc(new->type->size * new->n * new->m);
    if (!new->data) {
        *error = throwError("невозможно выделить память для matrix_t.data при создании", getMemoryError(), NULL);
		return NULL;
    }
    // Поведение по умолчанию: заполнить матрицу нулями
	if (data == NULL)
	{
		for (size_t i = 0; i < new->n * new->m; ++i)
		{
			*((char *)new->data) = 0;
		} 
	} else {
		if (!memcpy(new->data, data, new->type->size * new->n * new->m))
		{
            *error = throwError("невозможно скопировать matrix_t.data при создании", getMemoryError(), NULL);
			return NULL;
		}
	}
    return new;
}

void matrixFree(matrix_t* a)
{
    free(a->data);
    free(a);
}

matrix_t* matrixTranspose(matrix_t* a, error_t** error)
{
    void* new_data = malloc(a->type->size * a->n * a->m);
    if (!new_data) {
        *error = throwError("невозможно выделить память для matrix_t.data при транспонировании", getMemoryError(), NULL);
		return NULL;
    }
    for (unsigned int i = 0; i < a->m; ++i) {
        for (unsigned int j = 0; j < a->n; ++j) {
            if(!memcpy((char*)new_data + j * a->m * a->type->size + i * a->type->size, (char*)a->data + i * a->n * a->type->size + j * a->type->size, a->type->size))
            {
                *error = throwError("невозможно скопировать данные matrix_t при транспонировании", getMemoryError(), NULL);
				return NULL;
            }
        }
    }
	matrix_t *new = matrix(a->n, a->m, a->type, new_data, error);
    if (*error != NULL)
    {
        *error = throwError("при транспонировании", NULL, *error);
    }
	free(new_data);
	return new;
}

void* matrixGetElement(matrix_t* a, unsigned int i, unsigned int j, error_t** error)
{
    if (i < 0 || i >= a->m || j < 0 || j >= a->n)
    {
        *error = throwError("выход за границы matrix_t.data при попытке получения элемента", getLogicalError(), NULL);
        return NULL;
    }
    return (void *)((char *) a->data + a->n * a->type->size * i + a->type->size * j);
}

void* matrixSetElement(matrix_t* a, unsigned int i, unsigned int j, void* new_value, error_t** error)
{
    if (i >= a->m || j >= a->n)
    {
        *error = throwError("выход за границы matrix_t.data при попытке присваивания элемента", getLogicalError(), NULL);
        return NULL;
    }
	void* element = memcpy((void *)((char *) a->data + a->n * a->type->size * i + a->type->size * j), new_value, a->type->size);
	return element;
}

matrix_t* matrixSum(matrix_t* a, matrix_t* b, error_t** error)
{
    if (a->n != b->n || a->m != b->m) {
        *error = throwError("при сложении matrix_t размеры матриц не совпадают", getLogicalError(), NULL);
        return NULL;
    }
    if (a->type != b->type) {
        *error = throwError("при сложении matrix_t типы данных матриц не совпадают", getLogicalError(), NULL);
        return NULL;
    }
    matrix_t* new = malloc(sizeof(matrix_t));
    if (!new) {
        *error = throwError("при сложении matrix_t память под matrix_t не была выделена", getMemoryError(), NULL);
        return NULL;
    }
    new->m = a->m;
    new->n = a->n;
    new->type = a->type;
    new->data = malloc(a->type->size * a->n * a->m);
    if (!new->data) {
        *error = throwError("при сложении matrix_t память под matrix_t.data не была выделена", getMemoryError(), NULL);
        return NULL;
    }
    for (unsigned int i = 0; i < new->m; ++i) {
        for (unsigned int j = 0; j < new->n; ++j) {
            void* newElement;
            newElement = sum(new->type, (void*)((char*)a->data + a->n * a->type->size * i + j * a->type->size), (void*)((char*)b->data + b->n * b->type->size * i + j * b->type->size), error);
            if (*error != NULL)
            {
                *error = throwError("при сложении matrix_t", NULL, *error);
                return NULL;
            }
            if (!memcpy((void*)((char*)new->data + new->n * new->type->size * i + j * new->type->size), newElement, a->type->size))
            {
                *error = throwError("при сложении matrix_t matrix_t.data не была скопирована", getMemoryError(), NULL);
            }
            free(newElement);
        }
    }
    if (*error != NULL)
    {
        *error = throwError("при сложении matrix_t", NULL, *error);
        return NULL;
    }
    return new;
}

matrix_t* matrixProduct(matrix_t* a, matrix_t* b, error_t** error)
{
	if (a->n != b->m)
	{
        *error = throwError("при умножении matrix_t для размеров этих матриц операция умножения не имеет смысла", getLogicalError(), NULL);
        return NULL;
	}
    if (a->type != b->type) {
        *error = throwError("при умножении matrix_t типы данных различаются", getLogicalError(), NULL);
        return NULL;
    }
	matrix_t *newProduct = matrix(a->m, b->n, a->type, NULL, error);
    if (*error != NULL)
    {
        *error = throwError("при умножении matrix_t", NULL, *error);
        return NULL;
    }
	for (unsigned int i = 0; i < a->m; ++i)
	{
		for (unsigned int j = 0; j < b->n; ++j)
		{
			void *newElement = malloc(a->type->size);
            if (!newElement)
            {
                *error = throwError("при умножении matrix_t память под новый элемент не была выделена", getMemoryError(), NULL);
            }
			for (size_t i = 0; i < a->type->size; ++i)
			{
				*((char *)newElement + i) = 0;
			}
			void *tmpElement;
			void *tmpSumElement;
			for (unsigned int k = 0; k < a->n; ++k) 
            {
				tmpElement = product(a->type, (void *)((char *) a->data + a->type->size * a->n * i + a->type->size * k), (void *)((char *) b->data + b->type->size * b->n * k + b->type->size * j), error);
                if (*error != NULL)
                {
                    *error = throwError("при умножении matrix_t", NULL, *error);
                    return NULL;
                }
				tmpSumElement = sum(a->type, newElement, tmpElement, error);
                if (*error != NULL)
                {
                    *error = throwError("при умножении matrix_t", NULL, *error);
                    return NULL;
                }
				free(tmpElement);
				free(newElement);
				newElement = tmpSumElement;
			}
			matrixSetElement(newProduct, i, j, newElement, error);
            if (*error != NULL)
            {
                *error = throwError("при умножении matrix_t", NULL, *error);
                return NULL;
            }
			free(newElement);
		}
	}
	return newProduct;
}

matrix_t* matrixLinearCombination(struct FieldInfo* type, matrix_t* a, unsigned int index, void* alphas, error_t** error)
{
    matrix_t* new = matrix(a->m, a->n, a->type, a->data, error);
    if (*error)
    {
        *error = throwError("при попытке прибавить линейную комбинацию строк к строке matrix_t", NULL, *error);
        return NULL;
    }
    if (a->n < 2)
    {
        *error = throwError("при попытке прибавить линейную комбинацию строк к строке matrix_t для количества строк операция не имеет смысла", getLogicalError(), NULL);
        return NULL;
    }
    if (index >= a->m)
    {
        *error = throwError("при попытке прибавить линейную комбинацию строк к строке matrix_t строка index не входит в матрицу", getLogicalError(), NULL);
        return NULL;
    }
    if (type != new->type)
    {
        *error = throwError("при попытке прибавить линейную комбинацию строк к строке matrix_t у matrix_t и списка коэффицентов типы данных различаются", getLogicalError(), NULL);
        return NULL;
    }
    for (unsigned int i = 0; i < new->n; ++i) 
    {
        void* current = newZero(new->type, error);
        if (*error)
        {
            *error = throwError("при попытке прибавить линейную комбинацию строк к строке matrix_t", NULL, *error);
            return NULL;
        }
        for (unsigned int j = 0; j < new->m; ++j)
        {
            if (j < index)
            {
                void* currentProduct = product(new->type, matrixGetElement(a, j, i, error), (void *)((char *) alphas + j * type->size), error);
                if (*error)
                {
                    *error = throwError("при попытке прибавить линейную комбинацию строк к строке matrix_t", NULL, *error);
                    return NULL;
                }
                void* currentSum = sum(new->type, current, currentProduct, error);
                if (*error)
                {
                    *error = throwError("при попытке прибавить линейную комбинацию строк к строке matrix_t", NULL, *error);
                    return NULL;
                }
                free(current);
                free(currentProduct);
                current = currentSum;
                if (*error)
                {
                    *error = throwError("при попытке прибавить линейную комбинацию строк к строке matrix_t", NULL, *error);
                    return NULL;
                }
            }
            if (j > index)
            {
                void* currentProduct = product(new->type, matrixGetElement(a, j, i, error), (void *)((char *) alphas + (j - 1) * type->size), error);
                if (*error)
                {
                    *error = throwError("при попытке прибавить линейную комбинацию строк к строке matrix_t", NULL, *error);
                    return NULL;
                }
                void* currentSum = sum(new->type, current, currentProduct, error);
                if (*error)
                {
                    *error = throwError("при попытке прибавить линейную комбинацию строк к строке matrix_t", NULL, *error);
                    return NULL;
                }
                free(current);
                free(currentProduct);
                current = currentSum;
                if (*error)
                {
                    *error = throwError("при попытке прибавить линейную комбинацию строк к строке matrix_t", NULL, *error);
                    return NULL;
                }
            }
        }
        void* tmp = current;
        current = sum(new->type, current, matrixGetElement(a, index, i, error), error);
        free(tmp);
        if (*error)
        {
            *error = throwError("при попытке прибавить линейную комбинацию строк к строке matrix_t", NULL, *error);
            return NULL;
        }
        matrixSetElement(new, index, i, current, error);
        if (*error)
        {
            *error = throwError("при попытке прибавить линейную комбинацию строк к строке matrix_t", NULL, *error);
            return NULL;
        }
        free(current);
    }
    return new;
}
