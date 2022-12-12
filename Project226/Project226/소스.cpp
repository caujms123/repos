#include <stdio.h>
#define MAX 300

void cal(int module[][4][4],int i, int result,int check[]);
int max = 0;
int result = 0;

int makeBlock(int module[][4][4]) {
	int check[MAX];
	for (int i = 0; i < MAX; i++) check[i] = 0;
	cal(module, 0,0, check);
	return max;
}

void cal(int module[][4][4], int i ,int result,int check[]) {
	if (check[i]) goto outout;
	if (i == MAX-1) {
		if (max < result) max = result;
		return;
	}
	int moduleA[4][4][4];
	for (int j = 0; j < 4; j++) {
		for (int k = 0; k < 4; k++) {
			moduleA[0][k][j] = module[i][j][k];
		}
	}
	for (int j = 0; j < 3; j++) {
		for (int k = 0; k < 4; k++) {
			moduleA[j + 1][k][3] = moduleA[j][0][k];
			moduleA[j + 1][k][2] = moduleA[j][1][k];
			moduleA[j + 1][k][1] = moduleA[j][2][k];
			moduleA[j + 1][k][0] = moduleA[j][3][k];
		}
	} // module A 생성 (비교할 것)
	for (int m = 0; m < 4; m++) {
		for (int k = 0; k < 4; k++) {
			for (int l = 0; l < 4; l++) {
				printf("%d ", moduleA[m][k][l]);
			}
			printf("\n");
		}
	}
	printf("\n\n\n");
	int sum; // 합 길이
	for (int j = i+1; j < MAX; j++) { // 비교
		sum = 0;
		for (int k = 0; k < 4; k++) {
			for (int l = 0; l < 4; l++) {
				for (int m = 0; m < 4; m++) {
					if (sum != 0 && sum != (moduleA[k][l][m] + module[j][l][m]))  goto out;
					sum = moduleA[k][l][m] + module[j][l][m];
				}
			}
		}
		check[j] = 1;
		result += sum;
		cal(module, i+1, result,check);
		check[j] = 0;
		result -= sum;
	out:;
	}
outout:;
	cal(module,i+1 ,result,check);
	return;
}