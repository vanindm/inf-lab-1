#ifndef STD_DEF
#define STD_DEF
#include <stddef.h>
#endif

#ifndef FIELD_INFO
#define FIELD_INFO

struct FieldInfo
{
	unsigned int type;
	size_t size;
};

#endif

#ifndef TYPES
#define TYPES

typedef struct Integer {
	int value;
} integer_t;

int iSum(int a, int b);

typedef struct Real {
	float value;
} real_t;

double dSum(double a, double b);

// Тип комплексное число
typedef struct Complex
{
	float Re, Im;
} complex_t;


struct FieldInfo* GetIntFieldInfo();
struct FieldInfo* GetDoubleFieldInfo();
struct FieldInfo* GetComplexFieldInfo();

void* sum(struct FieldInfo* type, void* a, void *b);

complex_t cSum(complex_t* a, complex_t* b);

void* product(struct FieldInfo* type, void* a, void *b);

int iProduct(int a, int b);
double dProduct(double a, double b);
complex_t cProduct(complex a, complex b);

#endif
