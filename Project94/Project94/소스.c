#include<stdio.h>
#include<stdlib.h>
int main() {
	int dp2[200000];
	int aa[200000];
	int t;
	int a;
	int kk = 0;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &a);
		int sum = 300000;
		for (int j = 0; j < a; j++) {
			scanf("%d", &aa[j]);
			dp2[j] = 1;
		}
		if (a == 1) goto aaa;
		for (int j = 0; j < a; j++) {
			for (int k = kk; k < j; k++) {
				dp2[k]++;
				if (aa[j] == aa[k]) {
					if (sum > dp2[k]) {
						sum = dp2[k];
						
					}
				}
			}
		}
		if (sum < 300000) {
			printf("%d\n", sum);
			continue;
		}
	aaa:
		printf("-1\n");
	}
}