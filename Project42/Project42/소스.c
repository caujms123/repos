#include<stdio.h>
int main() {
	int n,m;
	int i, j;
	int a[400][1200];
	scanf("%d %d", &n, &m);
	for(i=0;i<n;i++)
		for(j=0;j<3*m;j++)
			scanf("%d", &a[i][j]);
	int I[400][400];
	for (i = 0; i < n; i++)
		for(j=1;j<m;j+=3)
			I[i][j] = 2126*a[i][j - 1] + 7152*a[i][j] + 722*a[i][j + 1];
	for (i = 0;i<n;i++) {
		for (j = 1;j<m;j+=3) {
			if (I[i][j] >= 0 && I[i][j] < 510000) {
				printf("#");
			}
			else if (I[i][j] >= 510000 && I[i][j] < 1020000) {
				printf("o");
			}
			else if (I[i][j] >= 1020000 && I[i][j] < 1530000) {
				printf("+");
			}
			else if (I[i][j] >= 1530000 && I[i][j] < 2040000) {
				printf("-");
			}
			else if (I[i][j] >= 2040000) {
				printf(".");
			}
		}
		printf("\n");
	}

}