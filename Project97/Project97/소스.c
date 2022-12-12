# include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int a[1000];
	int sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	if (n == 1) {
		printf("100");
		return 0;
	}
	int k;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) {
			k = a[i];
		}
		else k = a[i + 1];
	}
	double kk = ((double)sum / (n*k)) * 100.000000;
	printf("%lf", kk);
}