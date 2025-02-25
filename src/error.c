#include <error.h>

#include <string.h>

struct ErrorInfo* ERROR_NORMAL = null;
struct ErrorInfo* ERROR_LOGICAL = null;
struct ErrorInfo* ERROR_MEMORY = null;
struct ErrorInfo* ERROR_ARITHMETIC = null;

ErrorInfo* GetNormalError()
{
	if (!ERROR_NORMAL)
	{
		ERROR_NORMAL = malloc(sizeof(struct ErrorInfo));
		ERROR_NORMAL->code = 0;
		ERROR_NORMAL->message = NULL;
		ERROR_NORMAL->innerError = NULL;
	}
	return ERROR_NORMAL;
}

ErrorInfo* GetLogicalError()
{
	if (!ERROR_LOGICAL)
	{
		ERROR_LOGICAL = malloc(sizeof(struct ErrorInfo));
		ERROR_LOGICAL->code = 1;
		ERROR_LOGICAL->message = strdup("Логическая ошибка: ");
		ERROR_LOGICAL->innerError = NULL;
	}
	return ERROR_LOGICAL;
}

ErrorInfo* GetMemoryError()
{
	if (!ERROR_MEMORY)
	{
		ERROR_MEMORY = malloc(sizeof(struct ErrorInfo));
		ERROR_MEMORY->code = 2;
		ERROR_MEMORY->message = strdup("Ошибка памяти: ");
		ERROR_MEMORY->innerError = NULL;
	}
	return ERROR_MEMORY;
}

ErrorInfo* GetArithmeticError()
{
	if (!ERROR_ARITHMETIC)
	{
		ERROR_ARITHMETIC = malloc(sizeof(struct ErrorInfo));
		ERROR_ARITHMETIC->code = 3;
		ERROR_ARITHMETIC->message = strdup("Арифметическая ошибка: ");
		ERROR_ARITHMETIC->innerError = NULL;
	}
	return ERROR_ARITHMETIC;
}

void FreeErrorInfo()
{
	if(ERROR_NORMAL)
		free(ERROR_NORMAL);
	if(ERROR_LOGICAL)
		free(ERROR_LOGICAL);
	if(ERROR_MEMORY)
		free(ERROR_MEMORY);
	if(ERROR_ARITHMETIC)
		free(ERROR_ARITHMETIC);
}
