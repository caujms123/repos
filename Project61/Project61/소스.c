 #include<stdio.h>
#include<string.h>
	char *a[150000];
	int aa[150000];
	int main() {
		int i = 0;
		int A, B, C;
		int n;
		int sum = 0;
		scanf("%d %d %d", &A, &B, &C);
		for (i = 0; i < A + B + C; i++) {
			scanf("%s", a[i]);
			scanf("%d", &aa[i]);
		}
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			char aaa[10000];
			scanf("%s", aaa);
			for (int j = 0;; j++) {
				if (strcmp(a[j], aaa)) {
					sum += aa[j];
					break;
				}
			}
			printf("%d", sum);
		}
	}