#ifndef ERROR_H_
#define ERROR_H_

typedef struct ErrorInfo
{
	unsigned int code;
	char* message;
	struct ErrorInfo* innerError;
} error_t;

void freeErrorInfo();

ErrorInfo* getNormalError()
ErrorInfo* getLogicalError()
ErrorInfo* getMemoryError()
ErrorInfo* getArithmeticError()

error_t* throwError(char* message);

#endif
