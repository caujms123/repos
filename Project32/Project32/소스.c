#include<stdio.h>
int main() {
	int c = 0;
	int h, w;
	int i, j;
	int b;
	int sum = 0;
	int sum1 = 0;
	scanf("%d %d", &h, &w);
	int a[100][100] = { 0 };
	int ok[100][100] = { 0 };
	for (i = 0; i < h; i++)
		for (j = 0; j < w; j++)
			scanf("%d", &a[i][j]);
	for (i = 0; i < h; i++)
		for (j = 0; j < w; j++)
			sum += a[i][j];
	for (i = 0; i < w; i++) {
		b = a[i][0];
		for (j = 0; j < h; j++) {
			if (b < a[i][j])
				b = a[i][j];
		}
		sum1 += b;
		ok[i][j] = b;
	}

	for (i = 0; i < h; i++) {
		b = a[0][i];
		for (j = 0; j < w; j++) {
			if (b < a[j][i])
				b = a[j][i];
		}
		for (j = 0; j < w; j++) {
			if (ok[j][i] == 0) c++;
			if (b != ok[j][i] || ok[j][i] != 0)
				sum1 += b;
			if (c == w) sum1 += b;
		}
		c = 0;
	}
	printf("%d", sum - sum1);
}