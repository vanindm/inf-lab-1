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
    unsigned int n1 = 0, m1 = 0;
    error_t* error = NULL;
    if (!s)
        printf("Введите размеры MxN первой матрицы: ");
    scanf("%ud", &m1);
    scanf("%ud", &n1);
    void* data1 = malloc(n1 * m1 * type->size);
    if (!s)
        printf("Введите первую матрицу (через пробел): \n");
    for (unsigned int i = 0; i < n1 * m1; ++i)
    {
        void* new = readType(type, &error);
        if (error)
        {
            displayError(error);
            freeError(error);
            exit(error->code);
        }
        copyType(type, (void *)((char *) data1 + i * type->size), new, &error);
        if (error)
        {
            displayError(error);
            freeError(error);
            exit(error->code);
        }
        free(new);
    }
    matrix_t* mat1 = matrix(m1, n1, type, data1, &error);
    if (error)
    {
        displayError(error);
        freeError(error);
        exit(error->code);
    }

    unsigned int n2 = 0, m2 = 0;
    if (!s)
        printf("Введите размеры MxN первой матрицы: ");
    scanf("%ud", &m2);
    scanf("%ud", &n2);
    void* data2 = malloc(n2 * m2 * type->size);
    if (!s)
        printf("Введите вторую матрицу (через пробел): \n");
    for (unsigned int i = 0; i < n2 * m2; ++i)
    {
        void* new = readType(type, &error);
        if (error)
        {
            displayError(error);
            freeError(error);
            exit(error->code);
        }
        copyType(type, (void *)((char *) data2 + i * type->size), new, &error);
        if (error)
        {
            displayError(error);
            freeError(error);
            exit(error->code);
        }
        free(new);
    }
    matrix_t* mat2 = matrix(m2, n2, type, data2, &error);
    if (error)
    {
        displayError(error);
        freeError(error);
        exit(error->code);
    }

    matrix_t* matS = matrixSum(mat1, mat2, &error);
    if (error)
    {
        displayError(error);
        freeError(error);
        exit(error->code);
    }
    for (unsigned int i = 0; i < matS->m; ++i)
    {
        for (unsigned int j = 0; j < matS->n; ++j)
        {
            writeType(type, matrixGetElement(matS, i, j, &error), &error);
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

    free(data1);
    free(data2);
    matrixFree(mat1);
    matrixFree(mat2);
    matrixFree(matS);
}

void testProduct()
{
    unsigned int n1 = 0, m1 = 0;
    error_t* error = NULL;
    if (!s)
        printf("Введите размеры MxN первой матрицы: ");
    scanf("%ud", &m1);
    scanf("%ud", &n1);
    void* data1 = malloc(n1 * m1 * type->size);
    if (!s)
        printf("Введите первую матрицу (через пробел): \n");
    for (unsigned int i = 0; i < n1 * m1; ++i)
    {
        void* new = readType(type, &error);
        if (error)
        {
            displayError(error);
            freeError(error);
            exit(error->code);
        }
        copyType(type, (void *)((char *) data1 + i * type->size), new, &error);
        if (error)
        {
            displayError(error);
            freeError(error);
            exit(error->code);
        }
        free(new);
    }
    matrix_t* mat1 = matrix(m1, n1, type, data1, &error);
    if (error)
    {
        displayError(error);
        freeError(error);
        exit(error->code);
    }

    unsigned int n2 = 0, m2 = 0;
    if (!s)
        printf("Введите размеры MxN первой матрицы: ");
    scanf("%ud", &m2);
    scanf("%ud", &n2);
    void* data2 = malloc(n2 * m2 * type->size);
    if (!s)
        printf("Введите вторую матрицу (через пробел): \n");
    for (unsigned int i = 0; i < n2 * m2; ++i)
    {
        void* new = readType(type, &error);
        if (error)
        {
            displayError(error);
            freeError(error);
            exit(error->code);
        }
        copyType(type, (void *)((char *) data2 + i * type->size), new, &error);
        if (error)
        {
            displayError(error);
            freeError(error);
            exit(error->code);
        }
        free(new);
    }
    matrix_t* mat2 = matrix(m2, n2, type, data2, &error);
    if (error)
    {
        displayError(error);
        freeError(error);
        exit(error->code);
    }

    matrix_t* matP = matrixProduct(mat1, mat2, &error);
    if (error)
    {
        displayError(error);
        freeError(error);
        exit(error->code);
    }
    for (unsigned int i = 0; i < matP->m; ++i)
    {
        for (unsigned int j = 0; j < matP->n; ++j)
        {
            writeType(type, matrixGetElement(matP, i, j, &error), &error);
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

    free(data1);
    free(data2);
    matrixFree(mat1);
    matrixFree(mat2);
    matrixFree(matP);

}

void testLinearCombination()
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
    unsigned int row = 0;
    if (!s)
        printf("Введите номер строки, к которой прибавлять линейную комбинацию: ");
    scanf("%ud", &row);
    if (!s)
        printf("Введите коэффиценты (через пробел): ");
    void* alphas = malloc((mat->m - 1) * type->size);
    for (unsigned int i = 0; i < mat->m - 1; ++i)
    {
        void* new = readType(type, &error);
        if (error)
        {
            displayError(error);
            freeError(error);
            exit(error->code);
        }
        copyType(type, (void *)((char*) alphas + i * type->size), new, &error);
        if (error)
        {
            displayError(error);
            freeError(error);
            exit(error->code);
        }
        free(new);
    }
    matrix_t* matL = matrixLinearCombination(type, mat, row, alphas, &error);
    if (error)
    {
        displayError(error);
        freeError(error);
        exit(error->code);
    }
    for (unsigned int i = 0; i < matL->m; ++i)
    {
        for (unsigned int j = 0; j < matL->n; ++j)
        {
            writeType(type, matrixGetElement(matL, i, j, &error), &error);
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
    free(alphas);
    matrixFree(mat);
    matrixFree(matL);
}

void printUsage()
{
    printf("Использование: matrix [ОПЦИИ]\n\Получить матрицу(-ы) из стандартного ввода и произвести с ней следующие операции:\n\транспонирование (t), сумма (s), произведение (p), прибавить к строке линейную комбинацию других строк (l)\n\n\-t\tтип данных (i - integer, r - real, c - complex)\n\-o\tоперация\n-s\tтихий режим (для скриптов)\n");
}

int main(int argc, char **argv)
{
	char *typeArg = NULL;
	char *operationArg = NULL;
	int c;
    if (argc < 2)
    {
        printUsage();
        return 1;
    }
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
        case 'p':
            testProduct();
            break;
        case 't':
            testTransposition();
            break;
        case 'l':
            testLinearCombination();
            break;
        default:
            fprintf(stderr, "Указана неверная операция! (s/p/t/l)\n");
            return -1;
    }
    freeErrorInfo();
    freeFieldInfo();
    return 0;
}
