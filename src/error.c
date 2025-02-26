#include <error.h>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct ErrorInfo* ERROR_LOGICAL = NULL;
struct ErrorInfo* ERROR_MEMORY = NULL;
struct ErrorInfo* ERROR_ARITHMETIC = NULL;
struct ErrorInfo* ERROR_IO = NULL;

enum ErrorCode {
    CODE_LOGICAL = 1,
    CODE_MEMORY = 2,
    CODE_ARITHMETIC = 3,
    CODE_IO = 4
};

struct ErrorInfo* getLogicalError()
{
	if (!ERROR_LOGICAL)
	{
		ERROR_LOGICAL = malloc(sizeof(struct ErrorInfo));
		ERROR_LOGICAL->code = CODE_LOGICAL;
		ERROR_LOGICAL->message = strdup("логическая ошибка: ");
		ERROR_LOGICAL->innerError = NULL;
	}
	return ERROR_LOGICAL;
}

struct ErrorInfo* getMemoryError()
{
	if (!ERROR_MEMORY)
	{
		ERROR_MEMORY = malloc(sizeof(struct ErrorInfo));
		ERROR_MEMORY->code = CODE_MEMORY;
		ERROR_MEMORY->message = strdup("ошибка памяти: ");
		ERROR_MEMORY->innerError = NULL;
	}
	return ERROR_MEMORY;
}

struct ErrorInfo* getArithmeticError()
{
	if (!ERROR_ARITHMETIC)
	{
		ERROR_ARITHMETIC = malloc(sizeof(struct ErrorInfo));
		ERROR_ARITHMETIC->code = CODE_ARITHMETIC;
		ERROR_ARITHMETIC->message = strdup("арифметическая ошибка: ");
		ERROR_ARITHMETIC->innerError = NULL;
	}
	return ERROR_ARITHMETIC;
}

struct ErrorInfo* getIOError()
{
	if (!ERROR_IO)
	{
		ERROR_IO = malloc(sizeof(struct ErrorInfo));
		ERROR_IO->code = CODE_IO;
		ERROR_IO->message = strdup("ошибка ввода/вывода: ");
		ERROR_IO->innerError = NULL;
	}
	return ERROR_IO;
}

void freeErrorInfo()
{
	if(ERROR_LOGICAL)
		free(ERROR_LOGICAL);
	if(ERROR_MEMORY)
		free(ERROR_MEMORY);
	if(ERROR_ARITHMETIC)
		free(ERROR_ARITHMETIC);
}

void freeError(error_t* error)
{
    if (error->innerError)
        freeError(error->innerError);
    if(error->message)
        free(error->message);
    free(error);
}

error_t* _throwError(char* message, error_t* base)
{
    error_t* newError = malloc(sizeof(struct ErrorInfo));
    memcpy(newError, base, sizeof(struct ErrorInfo));
    newError->message = malloc(sizeof(char) * (strlen(message) + strlen(base->message) + 1));
    newError->message = strcat(newError->message, base->message);
    newError->message = strcat(newError->message, message);
    return newError;
}

error_t* throwError(char* message, error_t* base, error_t* additional)
{
    error_t* newError;
    if (base == NULL && additional != NULL)
    {
        newError = malloc(sizeof(struct ErrorInfo));
        newError->code = additional->code;
        newError->message = strdup(message);
    }
    if (base != NULL && additional == NULL) {
        newError = _throwError(message, base);
    }
    newError->innerError = additional;
    return newError;
}

void displayError(error_t* error)
{
    fprintf(stderr, "%s ", error->message);
    if (error->innerError)
    {
        displayError(error->innerError);
    }
    if (!error->innerError)
        fprintf(stderr, ".\n");
}
