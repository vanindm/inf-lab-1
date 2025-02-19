#ifndef FIELD_INFO
#define FIELD_INFO

struct FieldInfo
{
	unsigned int type;
	size_t size;
};


// Тип комплексное число
typedef struct Complex
{
	float Re, Im;
} complex;

FieldInfo* GetIntFieldInfo();
FieldInfo* GetDoubleFieldInfo();
FieldInfo* GetComplexFieldInfo();

void* sum(FieldInfo* type, void* a, void *b);

int iSum(int a, int b);
double dSum(double a, double b);
complex cSum(complex a, complex b);

void* product(FieldInfo* type, void* a, void *b);

int iProduct(int a, int b);
double dProduct(double a, double b);
complex cProduct(complex a, complex b);

#endif
