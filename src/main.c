#include <stdio.h>
#include <square_mat.h>

int main()
{
	smat_t *mat1, *mat2;
	int data[3][3] = {{1,2,3}, {1,2,3}, {1,2,3}};
	mat1 = smat(3, GetIntegerFieldInfo(), data);
	int data2[3][3] = {{4,5,6},{1,2,3},{0,0,0}};
	mat2 = smat(3, GetIntegerFieldInfo(), data2);
	smat_t* sum = smatSum(mat1, mat2);
	for (int i = 0; i < 9; i++) {
		printf("%d", *((int *)sum + i));
	}
	return 0;
}
