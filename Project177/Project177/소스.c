#include <stdio.h>
int dp[10000];
int dpp[10000];
int fibonacci(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else if (dp[n] != 0) {
		return dp[n];
	}
	else {
		return dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
	}
}
int fibonacci2(int n) {
	if (n == 0) {
		return 1;
	}
	else if (n == 1) {
		return 0;
	}
	else if (dpp[n] != 0) {
		return dpp[n];
	}
	else {
		return dpp[n] = fibonacci2(n - 1) + fibonacci2(n - 2);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		int a = fibonacci(k);
		int b = fibonacci2(k);
		printf("%d %d\n", b, a);
	}
}