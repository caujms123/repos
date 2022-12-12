# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	long long a, b, c;
	int h = 0;
	long long d[9] = { 0, };
	scanf("%lld %lld %lld", &a, &b, &c);
	long long f = a * b * c;

	for (long long i = 1; i <= 100000000; i * 10, h++) {
		if (f >= i)
			d[h] = (f % (i * 10)) / i;
	}
	for (int j = 0; j <= 9; j++) {
		printf("%lld \n", d[j]);
	}
	return 0;
}