#include <error.h>
#include <matrix.h>
#include <types.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

int s = 0;
struct FieldInfo* type;

void testTransposition()
{
    unsigned int n = 0, m = 0;
    error_t* error = NULL;
    if (!s)
        printf("Введите размеры MxN матрицы: ");
    scanf("%ud", &m);
    scanf("%ud", &n);
    void* data = malloc(n * m * type->size);
    if (!s)
        printf("Введите матрицу (через пробел): \n");
    for (unsigned int i = 0; i < n * m; ++i)
    {
        void* new = readType(type, &error);
        if (error)
        {
            displayError(error);
            freeError(error);
            exit(error->code);
        }
        copyType(type, (void *)((char *) data + i * type->size), new, &error);
        if (error)
        {
            displayError(error);
            freeError(error);
            exit(error->code);
        }
        free(new);
    }
    matrix_t* mat = matrix(m, n, type, data, &error);
    if (error)
    {
        displayError(error);
        freeError(error);
        exit(error->code);
    }
    matrix_t* matT = matrixTranspose(mat, &error);
    if (error)
    {
        displayError(error);
        freeError(error);
        exit(error->code);
    }
    for (unsigned int i = 0; i < matT->m; ++i)
    {
        for (unsigned int j = 0; j < matT->n; ++j)
        {
            writeType(type, matrixGetElement(matT, i, j, &error), &error);
            if (error)
            {
                displayError(error);
                freeError(error);
                exit(error->code);
            }
            printf(" ");
        }
        printf("\n");
    }
    free(data);
    matrixFree(mat);
    matrixFree(matT);
}

void testSum()
{

}

void testProduct()
{

}

void testLinearCombination()
{

}

int main(int argc, char **argv)
{
	int t = 0;
	int o = 0;
	char *typeArg = NULL;
	char *operationArg = NULL;
	int c;
	int opterr = 0;
	while((c = getopt(argc, argv, "t:o:s")) != -1)
	{
		switch(c)
		{
            case 's':
                s = 1;
                break;
			case 't':
				typeArg = optarg;
				break;
			case 'o':
				operationArg = optarg;
				break;
			case '?':
				if (optopt == 't' || optopt == 'o')
					fprintf(stderr, "Опция -%c требует тип в качестве аргумента. \n", optopt);
				else if (isprint(optopt))
					fprintf(stderr, "Неизвестная опция '-%c'. \n", optopt);
				else
					fprintf(stderr, "Неизвестный символ опции '\\x%x'. \n", optopt);
				return -1;
			default:
				abort();
		}
	}
	if (typeArg == NULL || operationArg == NULL)
	{
		fprintf(stderr, "Опции требуют аргумента!\n");
		return -1;
	}
    switch (*typeArg)
    {
        case 'i':
            type = getIntegerFieldInfo();
            break;
        case 'r':
            type = getRealFieldInfo();
            break;
        case 'c':
            type = getComplexFieldInfo();
            break;
        default:
            fprintf(stderr, "Указан неверный тип данных! (i/r/c)\n");
            return -1;
    }
    switch (*operationArg)
    {
        case 's':
            testSum();
            break;
        case 'm':
            testProduct();
            break;
        case 't':
            testTransposition();
            break;
        case 'l':
            testLinearCombination();
            break;
        default:
            fprintf(stderr, "Указана неверная операция! (s/m/t/l)\n");
            return -1;
    }
    freeErrorInfo();
    freeFieldInfo();
    return 0;
}
