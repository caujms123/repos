#include<stdio.h>
int main() {
	int t;
	int x, y;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &x, &y);
		if (y-x == 1) {
			printf("1");
			continue;
		}
		if ((y-x) % 2 == 0) {
			for (int n = 1;; n++) {
				if (n*(n + 1) / 2 == (y-x) / 2) {
					printf("%d\n", 2 * n);
					break;
				}
				else if (n*(n + 1) / 2 > (y-x) / 2) {
					printf("%d\n", (n - 1) * 2 + 1);
					break;
				}
			}
		}
		else if ((y-x) % 2 != 0) {
			int k = (y-x)- 1;
			for (int n = 1;; n++) {
				if (n*(n + 1) / 2 == k / 2) {
					printf("%d\n", 2 * n+1);
					break;
				}
				else if (n*(n + 1) / 2 > k / 2) {
					printf("%d\n", (n - 1) * 2 + 1+1);
					break;
				}
			}

		}
	}
}
