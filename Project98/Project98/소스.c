#include<stdio.h>
int a[100000];
int b[100000];
int c[100000];
int main() {
	int t;
	int n;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int count = 0;
		int uu = 0;
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[j]);
		}
		for (int j = 0; j < n; j++) {
			scanf("%d", &b[j]);
			c[j] = b[j] - a[j];
			if (c[j] < 0) {
				printf("NO\n");
				goto aaa;
			}
			if (c[j] != 0) {
				uu = 1;
			}
		}
		if (uu == 0) {
			printf("YES\n");
			goto aaa;
		}
		int kkkk;
		for (int j = 0; j < n - 1; j++) {
			if (c[j] != c[j + 1]) {
				if (c[j] != 0 && c[j + 1] != 0) {
					printf("NO\n");
					goto aaa;
				}
				count++;
				if (count > 2) {
					printf("NO\n");
					goto aaa;
				}
			}
		}
		printf("YES\n");
	aaa:;
	}
}