#pragma once
#include <stddef.h>

#ifndef TYPES_H_
#define TYPES_H_

struct FieldInfo {
    size_t size;
};

struct FieldInfo* getIntegerFieldInfo();
struct FieldInfo* getRealFieldInfo();
struct FieldInfo* getComplexFieldInfo();

void freeFieldInfo();

void* sum(struct FieldInfo* type, void* a, void* b, error_t* error);
void* sub(struct FieldInfo* type, void* a, void* b, error_t* error);
void* product(struct FieldInfo* type, void* a, void* b, error_t* error);
void* quotient(struct FieldInfo* type, void* a, void* b, error_t* error);

typedef struct Integer {
    int value;
} integer_t;

integer_t* integer(int value, error_t* error);
integer_t* iSum(integer_t* a, integer_t* b, error_t* error);
integer_t* iSub(integer_t* a, integer_t* b, error_t* error);
integer_t* iProduct(integer_t* a, integer_t* b, error_t* error);
integer_t* iQuotient(integer_t* a, integer_t* b, error_t* error);

typedef struct Real {
    double value;
} real_t;

real_t* real(double value, error_t* error);
real_t* rSum(real_t* a, real_t* b, error_t* error);
real_t* rSub(real_t* a, real_t* b, error_t* error);
real_t* rProduct(real_t* a, real_t* b, error_t* error);
real_t* rQuotient(real_t* a, real_t* b, error_t* error);

// Тип комплексное число
typedef struct Complex {
    double Re, Im;
} complex_t;

complex_t* complex(double Re, double Im, error_t* error);
complex_t* cSum(complex_t* a, complex_t* b, error_t* error);
complex_t* cSub(complex_t* a, complex_t* b, error_t* error);
complex_t* cProduct(complex_t* a, complex_t* b, error_t* error);
complex_t* cQuotient(complex_t* a, complex_t* b, error_t* error);

#endif
