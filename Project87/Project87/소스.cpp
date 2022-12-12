#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
	long long n, m;
	int t;
	scanf("%d", &t);
	for (int j = 0; j < t; j++) {
		long long sum = 1;
		scanf("%lld %lld", &n, &m);
		int k = 1;
		for (int i = n + 1; i <= m; i++,k++) {
			sum *= i;
			 if(k <= (m - n)) {
				sum /= k;
			}
		}
		for (; k <= (m - n); k++) {
			sum /= k;
		}

		printf("%lld\n", sum);
	}
}