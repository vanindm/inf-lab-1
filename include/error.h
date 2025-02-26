#ifndef ERROR_H_
#define ERROR_H_

typedef struct ErrorInfo
{
	unsigned int code;
	char* message;
	struct ErrorInfo* innerError;
} error_t;

void freeErrorInfo();

struct ErrorInfo* getLogicalError();
struct ErrorInfo* getMemoryError();
struct ErrorInfo* getArithmeticError();
struct ErrorInfo* getIOError();

void freeError(error_t* error);
error_t* _throwError(char* message, error_t* base);
error_t* throwError(char* message, error_t* base, error_t* additional);
void displayError(error_t* error);

#endif
