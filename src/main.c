#include <stdio.h>
#include <matrix.h>

int main()
{
	matrix_t *mat1, *mat2;
	int data[3][3] = {{1,2,3}, {1,2,3}, {1,2,3}};
	mat1 = matrix(3, 3, GetIntegerFieldInfo(), data);
	int data2[3][3] = {{4,5,6},{1,2,3},{0,0,0}};
	mat2 = matrix(3, 3, GetIntegerFieldInfo(), data2);
	matrix_t* sum = matrixSum(mat1, mat2);
	for (int i = 0; i < 9; i++) {
		printf("%d", *((int *)sum->data + i));
	}
	return 0;
}
