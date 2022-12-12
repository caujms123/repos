
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void) {
	long long N;
	scanf("%lli", &N);
	long long a = (float)3 / 2 * N*N + (float)5 / 2 * N + 1;
	long long result = a % 45678;
	printf("%lli", result);
	return 0;
}
