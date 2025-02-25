#pragma once

#include <matrix.h>
#include <types.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

matrix_t* matrix(unsigned int m, unsigned int n, struct FieldInfo* type, void* data)
{
    matrix_t* new = malloc(sizeof(matrix_t));
    if (!new) {
        fprintf(stderr, "Ошибка выделения памяти: %lu байт не было выделено.\n", sizeof(matrix_t));
        exit(1);
    }
    new->m = m;
    new->n = n;
    new->type = type;
    new->data = malloc(new->type->size * new->n * new->m);
    if (!new->data) {
        fprintf(stderr, "Ошибка выделения памяти: %lu байт не было выделено.\n", (new->type->size * new->n * new->m));
        exit(1);
    }
	if (data == NULL)
	{
		for (size_t i = 0; i < new->n * new->m; ++i)
		{
			*((char *)new->data) = 0;
		}
	} else {
		if (!memcpy(new->data, data, new->type->size * new->n * new->m))
		{
			fprintf(stderr, "Ошибка копирования: данные не были скопированы.\n");
			exit(1);
		}
	}
    return new;
}

void matrixFree(matrix_t* a)
{
    free(a->data);
    free(a);
}

void matrixTranspose(matrix_t* a)
{
    void* new_data = malloc(a->type->size * a->n * a->m);
    if (!new_data) {
        fprintf(stderr, "Ошибка выделения памяти: %lu байт не было выделено.\n", (a->type->size * a->n * a->m));
        exit(1);
    }
    unsigned int tmp = a->n;
    a->n = a->m;
    a->m = tmp;
    for (unsigned int i = 0; i < a->m; ++i) {
        for (unsigned int j = 0; j < a->n; ++j) {
            if(!memcpy((char*)new_data + i * a->n * a->type->size + j * a->type->size, (char*)a->data + j * a->m * a->type->size + i * a->type->size, a->type->size))
            {
                fprintf(stderr, "Ошибка копирования: данные не были скопированы.\n");
                exit(1);
            }
        }
    }
    free(a->data);
    a->data = new_data;
}

void* matrixGetElement(matrix_t* a, unsigned int i, unsigned int j)
{
    return (void *)((char *) a->data + a->n * a->type->size * i + a->type->size * j);
}

void matrixSetElement(matrix_t* a, unsigned int i, unsigned int j, void* new_value)
{
	memcpy((void *)((char *) a->data + a->n * a->type->size * i + a->type->size * j), new_value, a->type->size);
}

matrix_t* matrixSum(matrix_t* a, matrix_t* b)
{
    if (a->n != b->n || a->m != b->m) {
        fprintf(stderr, "Логическая ошибка: размеры матриц не совпадают.\n");
        exit(1);
    }
    if (a->type != b->type) {
        fprintf(stderr, "Логическая ошибка: типы данных матриц различаются.\n");
        exit(1);
    }
    matrix_t* new = malloc(sizeof(matrix_t));
    if (!new) {
        fprintf(stderr, "Ошибка выделения памяти: %lu байт не было выделено.\n", sizeof(matrix_t));
        exit(1);
    }
    new->m = a->m;
    new->n = a->n;
    new->type = a->type;
    new->data = malloc(a->type->size * a->n * a->m);
    if (!new->data) {
        fprintf(stderr, "Ошибка выделения памяти: %lu байт не было выделено.\n", a->type->size * a->n * a->m);
        exit(1);
    }
    for (unsigned int i = 0; i < new->m; ++i) {
        for (unsigned int j = 0; j < new->n; ++j) {
            void* new_element;
            new_element = sum(new->type, (void*)((char*)a->data + a->n * a->type->size * i + j * a->type->size), (void*)((char*)b->data + b->n * b->type->size * i + j * b->type->size));
            if (!memcpy((void*)((char*)new->data + new->n * new->type->size * i + j * new->type->size), new_element, a->type->size))
            {
                fprintf(stderr, "Ошибка копирования: данные не были скопированы.\n");
                exit(1);
            }
            free(new_element);
        }
    }
    return new;
}

matrix_t* matrixProduct(matrix_t* a, matrix_t* b)
{
	if (a->n != b->m)
	{
		fprintf(stderr, "Логическая ошибка: для матриц заданного размера умножение не определено.\n");
	}
    if (a->type != b->type) {
        fprintf(stderr, "Логическая ошибка: типы данных матриц различаются.\n");
        exit(1);
    }
	matrix_t *new_product = matrix(a->m, b->n, a->type, NULL);
	for (unsigned int i = 0; i < a->m; ++i)
	{
		for (unsigned int j = 0; j < a->n; ++j)
		{
			void *new_element = malloc(a->type->size);
			for (size_t i = 0; i < a->type->size; ++i)
			{
				*((char *)new_element + i) = 0;
			}
			void *tmp_element;
			void *tmp_sum_element;
			if (!new_element)
			{
				fprintf(stderr, "Ошибка выделения памяти: %lu байт не было выделено.\n", a->type->size);
				exit(1);
			}
			for (unsigned int k = 0; k < a->n; ++k) {
				tmp_element = product(a->type, (void *)((char *) a->data + a->type->size * a->n * i + a->type->size * k), (void *)((char *) b->data + b->type->size * b->n * k + b->type->size * j));
				tmp_sum_element = sum(a->type, new_element, tmp_element);
				free(tmp_element);
				free(new_element);
				new_element = tmp_sum_element;
			}
			matrixSetElement(new_product, i, j, new_element);
			free(new_element);
		}
	}
	return new_product;
}

matrix_t* matrixLinearCombination(matrix_t* a, unsigned int index, void* alphas, struct FieldInfo* type)
{
}
