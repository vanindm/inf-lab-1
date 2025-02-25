#include <matrix.h>
#include <stdio.h>
#include <types.h>

const int data[3][4] = { { 1, 2, 3, 4 }, { 1, 2, 3, 4 }, { 1, 2, 3, 4 } };
const int data2[3][4] = { { 4, 5, 6, 6 }, { 1, 2, 3, 6 }, { 0, 0, 0, 0 } };

int main()
{
    matrix_t *mat1, *mat2;
    error_t *error = NULL;
    mat1 = matrix(3, 4, getIntegerFieldInfo(), data, &error);
    mat2 = matrix(3, 4, getIntegerFieldInfo(), data2, &error);
    matrix_t* sum = matrixSum(mat1, mat2, &error);
    printf("Mat1:\n");
    for (int i = 0; i < mat1->m; i++)
    {
        for (int j = 0; j < mat1->n; j++)
        {
            printf("%d ", *((int *) matrixGetElement(mat1, i, j, &error)));
        }
        printf("\n");
    }
    printf("Mat2:\n");
    for (int i = 0; i < mat2->m; i++)
    {
        for (int j = 0; j < mat2->n; j++)
        {
            printf("%d ", *((int *) matrixGetElement(mat2, i, j, &error)));
        }
        printf("\n");
    }
    printf("Mat1 + Mat2:\n");
    for (int i = 0; i < mat1->m; i++)
    {
        for (int j = 0; j < mat1->n; j++)
        {
            printf("%d ", *((int *) matrixGetElement(sum, i, j, &error)));
        }
        printf("\n");
    }
    matrix_t* mat1T = matrixTranspose(mat1, &error);
    printf("(Mat1)^T:\n");
    for (int i = 0; i < mat1T->m; i++)
    {
        for (int j = 0; j < mat1T->n; j++)
        {
            printf("%d ", *((int *) matrixGetElement(mat1T, i, j, &error)));
        }
        printf("\n");
    }
    matrix_t* prod = matrixProduct(mat2, mat1, &error);
    if (error)
    {
        displayError(error);
        freeError(error);
    }
	printf("Mat2 * (Mat1)^T :\n");
    if (error)
    {
        displayError(error);
        freeError(error);
    }
    for (int i = 0; i < prod->m; i++)
    {
        for (int j = 0; j < prod->n; j++)
        {
            printf("%d ", *((int *) matrixGetElement(prod, i, j, &error)));
        }
        printf("\n");
    }
    matrixFree(mat1);
    matrixFree(mat2);
    matrixFree(sum);
    matrixFree(prod);
    freeFieldInfo();
    freeErrorInfo();
    return 0;
}
