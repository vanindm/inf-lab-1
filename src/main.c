#include <matrix.h>
#include <stdio.h>
#include <types.h>

const int data[3][4] = { { 1, 2, 3, 4 }, { 1, 2, 3, 4 }, { 1, 2, 3, 4 } };
const int data2[3][4] = { { 4, 5, 6, 6 }, { 1, 2, 3, 6 }, { 0, 0, 0, 0 } };

int main()
{
    matrix_t *mat1, *mat2;
    mat1 = matrix(3, 4, GetIntegerFieldInfo(), data);
    mat2 = matrix(3, 4, GetIntegerFieldInfo(), data2);
    matrix_t* sum = matrixSum(mat1, mat2);
    printf("Mat1:\n");
    for (int i = 0; i < mat1->m; i++)
    {
        for (int j = 0; j < mat1->n; j++)
        {
            printf("%d ", *(int *)((char *)mat1->data + mat1->n * mat1->type->size * i + j * mat1->type->size));
        }
        printf("\n");
    }
    printf("Mat2:\n");
    for (int i = 0; i < mat2->m; i++)
    {
        for (int j = 0; j < mat2->n; j++)
        {
            printf("%d ", *(int *)((char *)mat2->data + mat2->n * mat2->type->size * i + j * mat2->type->size));
        }
        printf("\n");
    }
    printf("Mat1 + Mat2:\n");
    for (int i = 0; i < mat1->m; i++)
    {
        for (int j = 0; j < mat1->n; j++)
        {
            printf("%d ", *(int *)((char *)sum->data + sum->n * sum->type->size * i + j * sum->type->size));
        }
        printf("\n");
    }
    matrixTranspose(mat1);
    printf("(Mat1)^T:\n");
    for (int i = 0; i < mat1->m; i++)
    {
        for (int j = 0; j < mat1->n; j++)
        {
            printf("%d ", *(int *)((char *)mat1->data + mat1->n * mat1->type->size * i + j * mat1->type->size));
        }
        printf("\n");
    }
    matrixFree(mat1);
    matrixFree(mat2);
    matrixFree(sum);
    FreeFieldInfo();
    return 0;
}
