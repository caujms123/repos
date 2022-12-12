# include<stdio.h>
int ddpp(int n) {
	if (n == 1) return 0;
	else if (n == 2) return 1;
	else if (n == 3) return 1;
	if (n % 3 == 0) return ddpp(n / 3) + 1;
	if (n % 2 == 0) return ddpp(n / 2) + 1;
	if (n % 2 != 0 && n % 3 != 0) return ddpp(n - 1) + 1;
}
int main() {
	int n;
	scanf("%d", &n);
	int count = ddpp(n);
	printf("%d", count);
}