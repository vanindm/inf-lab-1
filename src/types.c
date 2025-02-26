#include <types.h>
#include <error.h>

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct FieldInfo* INT_FIELD_INFO = NULL;
struct FieldInfo* REAL_FIELD_INFO = NULL;
struct FieldInfo* COMPLEX_FIELD_INFO = NULL;
unsigned int N_FIELD_INFO = 0;

struct FieldInfo* getIntegerFieldInfo()
{
    if (INT_FIELD_INFO == NULL) {
        INT_FIELD_INFO = malloc(sizeof(struct FieldInfo));
        INT_FIELD_INFO->size = sizeof(struct Integer);
    }
    return INT_FIELD_INFO;
}

struct FieldInfo* getRealFieldInfo()
{
    if (REAL_FIELD_INFO == NULL) {
        REAL_FIELD_INFO = malloc(sizeof(struct FieldInfo));
        REAL_FIELD_INFO->size = sizeof(struct Real);
    }
    return REAL_FIELD_INFO;
}

struct FieldInfo* getComplexFieldInfo()
{
    if (COMPLEX_FIELD_INFO == NULL) {
        COMPLEX_FIELD_INFO = malloc(sizeof(struct FieldInfo));
        COMPLEX_FIELD_INFO->size = sizeof(struct Complex);
    }
    return COMPLEX_FIELD_INFO;
}

void freeFieldInfo()
{
    if (INT_FIELD_INFO != NULL)
        free(INT_FIELD_INFO);
    if (REAL_FIELD_INFO != NULL)
        free(REAL_FIELD_INFO);
    if (COMPLEX_FIELD_INFO != NULL)
        free(COMPLEX_FIELD_INFO);
}

integer_t* integer(int value, error_t** error)
{
    integer_t* new = malloc(sizeof(integer_t));
    if (!new)
    {
        *error = throwError("невозможно выделить память для integer при создании", getMemoryError(), NULL);
        return NULL;
    }
    new->value = value;
    return new;
}

integer_t* iSum(integer_t* a, integer_t* b, error_t** error)
{
    integer_t* new = malloc(sizeof(integer_t));
    if (!new)
    {
        *error = throwError("невозможно выделить память для integer при сложении", getMemoryError(), NULL);
        return NULL;
    }
    new->value = a->value + b->value;
    return new;
}

integer_t* iSub(integer_t* a, integer_t* b, error_t** error)
{
    integer_t* new = malloc(sizeof(integer_t));
    if (!new)
    {
        *error = throwError("невозможно выделить память для integer при вычитании", getMemoryError(), NULL);
        return NULL;
    }
    new->value = a->value - b->value;
    return new;
}

integer_t* iProduct(integer_t* a, integer_t* b, error_t** error)
{
    integer_t* new = malloc(sizeof(integer_t));
    if (!new)
    {
        *error = throwError("невозможно выделить память для integer при умножении", getMemoryError(), NULL);
        return NULL;
    }
    new->value = a->value * b->value;
    return new;
}

integer_t* iQuotient(integer_t* a, integer_t* b, error_t** error)
{
    integer_t* new = malloc(sizeof(integer_t));
    if (!new)
    {
        *error = throwError("невозможно выделить память для integer при делении", getMemoryError(), NULL);
        return NULL;
    }
    new->value = a->value / b->value;
    return new;
}

integer_t* iRead(error_t** error)
{
    integer_t* new = malloc(sizeof(integer_t)); 
    if (!new)
    {
        *error = throwError("невозможно выделить память для integer при вводе из stdin", getMemoryError(), NULL);
        return NULL;
    }
    scanf("%d", &new->value);
    return new;
}

void iWrite(integer_t* a, error_t** error)
{
    if(printf("%d", a->value) < 0)
    {
        *error = throwError("ошибка при выводе integer_t", getIOError(), NULL);
    }
}

real_t* real(double value, error_t** error)
{
    real_t* new = malloc(sizeof(real_t));
    if (!new)
    {
        *error = throwError("невозможно выделить память для real при создании", getMemoryError(), NULL);
        return NULL;
    }
    new->value = value;
    return new;
}

real_t* rSum(real_t* a, real_t* b, error_t** error)
{
    real_t* new = malloc(sizeof(real_t));
    if (!new)
    {
        *error = throwError("невозможно выделить память для real при сложении", getMemoryError(), NULL);
        return NULL;
    }
    new->value = a->value + b->value;
    return new;
}

real_t* rSub(real_t* a, real_t* b, error_t** error)
{
    real_t* new = malloc(sizeof(real_t));
    if (!new)
    {
        *error = throwError("невозможно выделить память для real при вычитании", getMemoryError(), NULL);
        return NULL;
    }
    new->value = a->value - b->value;
    return new;
}

real_t* rProduct(real_t* a, real_t* b, error_t** error)
{
    real_t* new = malloc(sizeof(real_t));
    if (!new)
    {
        *error = throwError("невозможно выделить память для real при умножении", getMemoryError(), NULL);
        return NULL;
    }
    new->value = a->value * b->value;
    return new;
}

real_t* rQuotient(real_t* a, real_t* b, error_t** error)
{
    real_t* new = malloc(sizeof(real_t));
    if (!new)
    {
        *error = throwError("невозможно выделить память для real при делении", getMemoryError(), NULL);
        return NULL;
    }
    new->value = a->value / b->value;
    return new;
}

real_t* rRead(error_t** error)
{
    real_t* new = malloc(sizeof(real_t)); 
    if (!new)
    {
        *error = throwError("невозможно выделить память для real при вводе из stdin", getMemoryError(), NULL);
        return NULL;
    }
    scanf("%lf", &new->value);
    return new;
}

void rWrite(real_t* a, error_t** error)
{
    if(printf("%lf", a->value) < 0)
    {
        *error = throwError("ошибка при выводе real_t", getIOError(), NULL);
    }
}

complex_t* complex(double Re, double Im, error_t** error)
{
    complex_t* new = malloc(sizeof(complex_t));
    if (!new)
    {
        *error = throwError("невозможно выделить память для complex при создании", getMemoryError(), NULL);
        return NULL;
    }
    new->Re = Re;
    new->Im = Im;
    return new;
}

complex_t* cSum(complex_t* a, complex_t* b, error_t** error)
{
    complex_t* new = malloc(sizeof(complex_t));
    if (!new)
    {
        *error = throwError("невозможно выделить память для complex при сложении", getMemoryError(), NULL);
        return NULL;
    }
    new->Re = a->Re + b->Re;
    new->Im = a->Im + b->Im;
    return new;
}

complex_t* cSub(complex_t* a, complex_t* b, error_t** error)
{
    complex_t* new = malloc(sizeof(complex_t));
    if (!new)
    {
        *error = throwError("невозможно выделить память для complex при вычитании", getMemoryError(), NULL);
        return NULL;
    }
    new->Re = a->Re - b->Re;
    new->Im = a->Im - b->Im;
    return new;
}

complex_t* cProduct(complex_t* a, complex_t* b, error_t** error)
{
    complex_t* new = malloc(sizeof(complex_t));
    if (!new)
    {
        *error = throwError("невозможно выделить память для complex при умножении", getMemoryError(), NULL);
        return NULL;
    }
    new->Re = a->Re * b->Re - a->Im * b->Im;
    new->Im = a->Re * b->Im + a->Im * b->Re;
    return new;
}

complex_t* cQuotient(complex_t* a, complex_t* b, error_t** error)
{
    complex_t* new = malloc(sizeof(complex_t));
    if (!new)
    {
        *error = throwError("невозможно выделить память для complex при делении", getMemoryError(), NULL);
        return NULL;
    }
    complex_t inverse;
    inverse.Re = (b->Re / (b->Re * b->Re + b->Im * b->Im));
    inverse.Im = (b->Im / (b->Re * b->Re + b->Im * b->Im));
    new->Re = a->Re* inverse.Re - a->Im* inverse.Im;
    new->Im = a->Re* inverse.Im + a->Im* inverse.Re;
    return new;
}

complex_t* cRead(error_t** error)
{
    complex_t* new = malloc(sizeof(complex_t)); 
    if (!new)
    {
        *error = throwError("невозможно выделить память для complex_t при вводе из stdin", getMemoryError(), NULL);
        return NULL;
    }
    scanf("%lf %lf", &new->Re, &new->Im);
    return new;
}

void cWrite(complex_t* a, error_t** error)
{
    if(printf("%lf %lf", a->Re, a->Im) < 0)
    {
        *error = throwError("ошибка при выводе complex_t", getIOError(), NULL);
    }
}

void* newZero(struct FieldInfo* type, error_t** error)
{
    void* new = malloc(type->size);
    if (!new)
    {
        *error = throwError("невозможно выделить память для нуля абстрактного типа", getMemoryError(), NULL);
        return NULL;
    }
    for (unsigned int i = 0 ; i < type->size; ++i)
    {
        *((char *) new + i) = 0;
    }
    return new;
}

void* sum(struct FieldInfo* type, void* a, void* b, error_t** error)
{
    void* new;
    if (type == getIntegerFieldInfo()) {
        new = (void*)iSum((integer_t*)a, (integer_t*)b, error);
    } else if (type == getRealFieldInfo()) {
        new = (void*)rSum((real_t*)a, (real_t*)b, error);
    } else if (type == getRealFieldInfo()) {
        new = (void*)cSum((complex_t*)a, (complex_t*)b, error);
    }
    return new;
}

void* sub(struct FieldInfo* type, void* a, void* b, error_t** error)
{
    void* new;
    if (type == getIntegerFieldInfo()) {
        new = (void*)iSub((integer_t*)a, (integer_t*)b, error);
    } else if (type == getRealFieldInfo()) {
        new = (void*)rSub((real_t*)a, (real_t*)b, error);
    } else if (type == getRealFieldInfo()) {
        new = (void*)cSub((complex_t*)a, (complex_t*)b, error);
    }
    return new;
}

void* product(struct FieldInfo* type, void* a, void* b, error_t** error)
{
    void* new;
    if (type == getIntegerFieldInfo()) {
        new = (void*)iProduct((integer_t*)a, (integer_t*)b, error);
    } else if (type == getRealFieldInfo()) {
        new = (void*)rProduct((real_t*)a, (real_t*)b, error);
    } else if (type == getRealFieldInfo()) {
        new = (void*)cProduct((complex_t*)a, (complex_t*)b, error);
    }
    return new;
}

void* quotient(struct FieldInfo* type, void* a, void* b, error_t** error)
{
    void* new;
    if (type == getIntegerFieldInfo()) {
        new = (void*)iQuotient((integer_t*)a, (integer_t*)b, error);
    } else if (type == getRealFieldInfo()) {
        new = (void*)rQuotient((real_t*)a, (real_t*)b, error);
    } else if (type == getRealFieldInfo()) {
        new = (void*)cQuotient((complex_t*)a, (complex_t*)b, error);
    }
    return new;
}

void* readType(struct FieldInfo* type, error_t** error)
{
    void* new;
    if (type == getIntegerFieldInfo()) {
        new = (void*)iRead(error);
    } else if (type == getRealFieldInfo()) {
        new = (void*)rRead(error);
    } else if (type == getComplexFieldInfo()) {
        new = (void*)cRead(error);
    }
    return new;
}

void writeType(struct FieldInfo* type, void* a, error_t** error)
{
    if (type == getIntegerFieldInfo()) {
        iWrite((integer_t *)a, error);
    } else if (type == getRealFieldInfo()) {
        rWrite((real_t *)a, error);
    } else if (type == getComplexFieldInfo()) {
        cWrite((complex_t *)a, error);
    }
}

void* copyType(struct FieldInfo* type, void* dst, void* src, error_t** error)
{
    void* new = memcpy(dst, src, type->size);
    if (!new)
    {
        *error = throwError("невозможно скопировать абстрактный тип", getMemoryError(), NULL);
        return NULL;
    }
    return new;
}
