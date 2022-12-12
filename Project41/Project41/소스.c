#include<stdio.h>
int main() {
	int n = 0;
	int a[1001];
	int b[1001];
	int c = 0;
	int k = 0;
	int sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1 - i; j++)
			if (a[j] < a[j + 1]) {
				k = a[j];
				a[j] = a[j + 1];
				a[j + 1] = k;
			}
	for (int i = 0; i < n; i++) {
		sum += a[i] * i;
	}
	sum += n;
	printf("%d \n", sum);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i] == b[j]) {
				printf("%d ", j+1);
				b[j] = 0;
				break;
			}
		}
	}
}