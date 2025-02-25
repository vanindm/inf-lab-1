#include <stddef.h>

#ifndef FIELD_INFO
#define FIELD_INFO

struct FieldInfo
{
	size_t size;
};

struct FieldInfo* GetIntegerFieldInfo();
struct FieldInfo* GetRealFieldInfo();
struct FieldInfo* GetComplexFieldInfo();

void FreeFieldInfo();

#endif

#ifndef TYPES
#define TYPES

void* sum(struct FieldInfo* type, void* a, void *b);
void* sub(struct FieldInfo* type, void* a, void *b);
void* product(struct FieldInfo* type, void* a, void *b);
void* quotient(struct FieldInfo* type, void* a, void *b);

typedef struct Integer {
	int value;
} integer_t;

integer_t* integer(int value);
integer_t* iSum(integer_t* a, integer_t* b);
integer_t* iSub(integer_t* a, integer_t* b);
integer_t* iProduct(integer_t* a, integer_t* b);
integer_t* iQuotient(integer_t* a, integer_t* b);

typedef struct Real {
	double value;
} real_t;

real_t* real(double value);
real_t* rSum(real_t* a, real_t* b);
real_t* rSub(real_t* a, real_t* b);
real_t* rProduct(real_t* a, real_t* b);
real_t* rQuotient(real_t* a, real_t* b);

// Тип комплексное число
typedef struct Complex
{
	double Re, Im;
} complex_t;

complex_t* complex(double Re, double Im);
complex_t* cSum(complex_t* a, complex_t* b);
complex_t* cSub(complex_t* a, complex_t* b);
complex_t* cProduct(complex_t* a, complex_t* b);
complex_t* cQuotient(complex_t* a, complex_t* b);

#endif
