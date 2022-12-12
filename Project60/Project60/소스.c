#include<stdio.h>
#include<math.h>
int main() {
	int a;
	scanf("%d", &a);
	for (int n = 1;; n++) {
		if (a >= n * (pow(2, n) - 1) + n && a <= (n + 1)*(pow(2, n + 1) - 1) + n) {
			printf("%d", n);
			return 0;
		}
	}
}