#include<stdio.h>
#include<string.h>
int main() {
	int a[31], b[31];
	a[1] = 1; a[2] = 0;
	b[1] = 0; b[2] = 1;
	int aa, bb;
	int day, n;
	scanf_s("%d %d", &day, &n);
	for (int i = 3; i <= day; i++) {
		a[i] = a[i - 1] + a[i - 2];
		b[i] = b[i - 1] + b[i - 2];
	}
	for (int j = 0;; j++) {
		for (int k = j;; k++) {
			if (n == a[day] * j + b[day] * k) {
				printf("%d\n%d", j, k);
				return 0;
			}
			if (n < a[day] * j + b[day] * k) {
				break;
			}
		}
	}
}