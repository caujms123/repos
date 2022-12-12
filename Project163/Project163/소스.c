#include<stdio.h>
#include<math.h>
int main() {
	long long t;
	long long x, y;
	scanf("%lld", &t);
	for (int i = 0; i < t; i++) {
		scanf("%lld %lld", &x, &y);
		long long k = y - x;
		if (k == 1) {
			printf("1\n");
			continue;
		}
		if (k % 2 == 0) {
			for (long long n = 1;; n++) {
				long long d = n * (n + 1) / 2;
				if (d == k / 2) {
					printf("%lld\n", 2 * n);
					break;
				}
				else if (d > k / 2) {
					printf("%lld\n", (n - 1) * 2 + 1);
					break;
				}
			}
		}
		else if (k % 2 != 0) {
			k--;
			for (long long n = 1;; n++) {
				long long d = n * (n + 1) / 2;
				if (d == k / 2) {
					printf("%lld\n", 2 * n + 1);
					break;
				}
				else if (d > k / 2) {
					printf("%lld\n", (n - 1) * 2 + 1 + 1);
					break;
				}
			}
		}
	}
}