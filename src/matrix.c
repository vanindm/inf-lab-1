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
    new->data = malloc(new->type->size* new->n* new->m);
    memcpy(new->data, data, new->type->size* new->n* new->m);
    if (!new->data) {
        fprintf(stderr, "Ошибка выделения памяти: %lu байт не было выделено.\n", (new->type->size* new->n* new->m));
        exit(1);
    }
    return new;
}

void matrixFree(matrix_t* a)
{
    free(a->data);
    free(a);
}

matrix_t* matrixTranspose(matrix_t* a)
{
    void* new_data = malloc(a->type->size * a->n * a->m);
    if (!new_data) {
        fprintf(stderr, "Ошибка выделения памяти: %lu байт не было выделено.\n", (a->type->size * a->n * a->m));
        exit(1);
    }
    unsigned int tmp = a->n;
    a->n = a->m;
    a->m = tmp;
    for (unsigned int i = 0; i < a->n; i++) {
        for (unsigned int j = 0; j < a->m; j++) {
            memcpy((char*)new_data + i * a->m * a->type->size + j * a->type->size, (char*)new_data + j * a->m * a->type->size + i * a->type->size, a->type->size);
        }
    }
    free(a->data);
    a->data = new_data;
}

matrix_t* matrixSum(matrix_t* a, matrix_t* b)
{
    if (a->n != b->n || a->n != b->m) {
        fprintf(stderr, "Логическая ошибка: размеры матриц не совпадают.\n");
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
            new_element = sum(new->type, (void*)((char*)a->data + a->m * a->type->size * i + j * a->type->size), (void*)((char*)b->data + b->m * b->type->size * i + j * b->type->size));
            memcpy((void*)((char*)new->data + new->m* new->type->size* i + j* new->type->size), new_element, a->type->size);
            free(new_element);
        }
    }
    return new;
}

matrix_t* matrixProduct(matrix_t* a, matrix_t* b)
{
}

matrix_t* matrixLinearCombination(matrix_t* a, unsigned int index, void* alphas, struct FieldInfo* type)
{
}
