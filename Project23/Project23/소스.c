# include<stdio.h>
int main() {
	int A, B, a, b, n, w;
	scanf("%d %d %d %d", &a, &b, &n, &w);
	int h = (w - b * n), j = (a - b), k = (w - a * n), l = (b - a);
	if (a == b && n == 2 && w== n*a) {
		printf("1 1");
		return 0;
	}
	else if (a == b) {
		printf("-1");
		return 0;
	}
	else if (w < n) {
		printf("-1");
		return 0;
	}
	if (h % j != 0 || k % l != 0) {
		printf("-1");
		return 0;
	}
	A = (w - b * n) / (a - b);
	B = (w - a * n) / (b - a);
	if (A <= 0 || B <= 0 ) {
		printf("-1");
		return 0;
	}
	if (a == b && n == 2 && w >= n) {
		printf("1 1");
		return 0;
	}
	printf("%d %d",A,B);
}