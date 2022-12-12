#include<stdio.h>
int s[1001];
int s2[1001];
int c = 0;
int a[1001][1001] = { 0 };
int main() {
	int h, w;
	int i, j;
	long long sum=0;
	scanf("%d %d", &h, &w);
	for (i = 0; i < h; i++)
		for (j = 0; j < w; j++)
			scanf("%d", &a[i][j]);
	for (i = 0; i < h; i++)
		for (j = 0; j < w; j++)
			sum += a[i][j];

	for (i = 0; i < h; i++) {
		s[i] = a[i][0];
		for (j = 1; j < w; j++) {
			if (s[i] < a[i][j])
				s[i] = a[i][j];
		}
		sum -= s[i];
	}
	for (j = 0; j < w; j++) {
		s2[j] = a[0][j];
		for (i = 0; i < h; i++) {
			if (s2[j] < a[i][j])
				s2[j] = a[i][j];
		}
		for (i = 0;i<h; i++) {
			if (s[i] == s2[j]) {
				c++;
			}
		}
		if (c == 0) {
			sum -= s2[j];
		}
		c = 0;
	}
	printf("%lld", sum);
}