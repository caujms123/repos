#include <stdio.h>
#include <math.h>

int main() {
	int n;
	scanf("%d", &n);
	long long f[91] = {0};
	f[1] = 1;
	f[2] = 1;
	for (int i = 3; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}
	printf("%lld",f[n]);
}

