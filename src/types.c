#include <types.h>
#include <stdlib.h>

struct FieldInfo* INT_FIELD_INFO;
struct FieldInfo* REAL_FIELD_INFO;
struct FieldInfo* COMPLEX_FIELD_INFO;
unsigned int N_FIELD_INFO = 0;

struct FieldInfo* GetIntegerFieldInfo()
{
	if (INT_FIELD_INFO == NULL)
	{
		INT_FIELD_INFO = malloc(sizeof(struct FieldInfo));
		INT_FIELD_INFO->size = sizeof(struct Integer);
	}
	return INT_FIELD_INFO;
}

struct FieldInfo* GetRealFieldInfo()
{
	if (REAL_FIELD_INFO == NULL)
	{
		REAL_FIELD_INFO = malloc(sizeof(struct FieldInfo));
		INT_FIELD_INFO->size = sizeof(struct Real);
	}
	return REAL_FIELD_INFO;
}

struct FieldInfo* GetComplexFieldInfo()
{
	if (COMPLEX_FIELD_INFO == NULL)
	{
		COMPLEX_FIELD_INFO = malloc(sizeof(struct FieldInfo));
		INT_FIELD_INFO->size = sizeof(struct Complex);
	}
	return COMPLEX_FIELD_INFO;
}

integer_t* integer(int value)
{
	integer_t* new = malloc(sizeof(integer_t));
	new->value = value;
	return new;
}

integer_t* iSum(integer_t* a, integer_t* b)
{
	integer_t* pNew = malloc(sizeof(integer_t));
	pNew->value = a->value + b->value;
	return pNew;
}

integer_t* iSub(integer_t* a, integer_t* b)
{
	integer_t* new = malloc(sizeof(integer_t));
	new->value = a->value - b->value;
	return new;
}

integer_t* iProduct(integer_t* a, integer_t* b)
{
	integer_t* new = malloc(sizeof(integer_t));
	new->value = a->value * b->value;
	return new;
}

integer_t* iQuotient(integer_t* a, integer_t* b)
{
	integer_t* new = malloc(sizeof(integer_t));
	new->value = a->value / b->value;
	return new;
}

real_t* real(double value)
{
	real_t* new = malloc(sizeof(real_t));
	new->value = value;
	return new;
}

real_t* rSum(real_t* a, real_t* b)
{
	real_t* new = malloc(sizeof(real_t));
	new->value = a->value + b->value;
	return new;
}

real_t* rSub(real_t* a, real_t* b)
{
	real_t* new = malloc(sizeof(real_t));
	new->value = a->value - b->value;
	return new;
}

real_t* rProduct(real_t* a, real_t* b)
{
	real_t* new = malloc(sizeof(real_t));
	new->value = a->value * b->value;
	return new;
}

real_t* rQuotient(real_t* a, real_t* b)
{
	real_t* new = malloc(sizeof(real_t));
	new->value = a->value / b->value;
	return new;
}

complex_t* complex(double Re, double Im)
{
	complex_t* new = malloc(sizeof(complex_t));
	new->Re = Re;
	new->Im = Im;
	return new;
}

complex_t* cSum(complex_t* a, complex_t* b)
{
	complex_t* new = malloc(sizeof(complex_t));
	new->Re = a->Re + b->Re;
	new->Im = a->Im + b->Im;
	return new;
}

complex_t* cSub(complex_t* a, complex_t* b)
{
	complex_t* new = malloc(sizeof(complex_t));
	new->Re = a->Re - b->Re;
	new->Im = a->Im - b->Im;
	return new;
}

complex_t* cProduct(complex_t* a, complex_t* b)
{
	complex_t* new = malloc(sizeof(complex_t));
	new->Re = a->Re * b->Re - a->Im * b->Im;
	new->Im = a->Re * b->Im + a->Im * b->Re;
	return new;
}

complex_t* cQuotient(complex_t* a, complex_t* b)
{
	complex_t* new = malloc(sizeof(complex_t));
	complex_t inverse;
	inverse.Re = (b->Re / (b->Re * b->Re + b->Im * b->Im));
	inverse.Im = (b->Im / (b->Re * b->Re + b->Im * b->Im));
	new->Re = a->Re * inverse.Re - a->Im * inverse.Im;
	new->Im = a->Re * inverse.Im + a->Im * inverse.Re;
	return new;
}

void* sum(struct FieldInfo* type, void* a, void *b)
{
	void* new;
	if (type == GetIntegerFieldInfo()) 
	{
		new = (void *) iSum((integer_t *) a,(integer_t *) b);
	}
	else if (type == GetRealFieldInfo()) 
	{
		new = (void *) rSum((real_t *) a, (real_t *) b);
	}
	else if (type == GetRealFieldInfo()) 
	{
		new = (void *) cSum((complex_t *) a, (complex_t *) b);
	}
	return new;
}

void* sub(struct FieldInfo* type, void* a, void *b)
{
	void* new;
	if (type == GetIntegerFieldInfo()) 
	{
		new = (void *) iSub((integer_t *) a,(integer_t *) b);
	}
	else if (type == GetRealFieldInfo()) 
	{
		new = (void *) rSub((real_t *) a, (real_t *) b);
	}
	else if (type == GetRealFieldInfo()) 
	{
		new = (void *) cSub((complex_t *) a, (complex_t *) b);
	}
	return new;
}

void* product(struct FieldInfo* type, void* a, void *b)
{
	void* new;
	if (type == GetIntegerFieldInfo()) 
	{
		new = (void *) iProduct((integer_t *) a,(integer_t *) b);
	}
	else if (type == GetRealFieldInfo()) 
	{
		new = (void *) rProduct((real_t *) a, (real_t *) b);
	}
	else if (type == GetRealFieldInfo()) 
	{
		new = (void *) cProduct((complex_t *) a, (complex_t *) b);
	}
	return new;
}

void* quotient(struct FieldInfo* type, void* a, void *b)
{
	void* new;
	if (type == GetIntegerFieldInfo()) 
	{
		new = (void *) iQuotient((integer_t *) a,(integer_t *) b);
	}
	else if (type == GetRealFieldInfo()) 
	{
		new = (void *) rQuotient((real_t *) a, (real_t *) b);
	}
	else if (type == GetRealFieldInfo()) 
	{
		new = (void *) cQuotient((complex_t *) a, (complex_t *) b);
	}
	return new;
}
