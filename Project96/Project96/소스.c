#include<stdio.h>
#include<stdlib.h>
int aa[200000];
int main() {
	int t;
	int a;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int pp = 0;
		scanf("%d", &a);
		int sum = 300000;
		for (int j = 0; j < a; j++) {
			scanf("%d", &aa[j]);
		}
		if (a == 1) goto aaa;
		for (int j = 0; j < a; j++) {
			if (sum != 300000) {
				pp = j - sum;
			}
			for (int k = pp; k < j; k++) {
				if (aa[j] == aa[k]) {
					if (sum > j-k+1) sum = j-k+1;
				}
			}
		}
		if (sum != 300000) {
			printf("%d\n", sum);
			continue;
		}
	aaa:
		printf("-1\n");
	}
}