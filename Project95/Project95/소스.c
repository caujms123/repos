#include<stdio.h>
#include<stdlib.h>
int dp2[200000];
int aa[200000];
int main() {
	int t;
	int a;
	int kk = 0;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		kk = 0;
		scanf("%d", &a);
		int sum = 300000;
		for (int j = 0; j < a; j++) {
			scanf("%d", &aa[j]);
		}
		if (a == 1) goto aaa;
		for (int j = 0; j < a; j++) {
			if (kk == 0) {
				for (int k = kk; k < j; k++) {
					dp2[k]++;
					if (aa[j] == aa[k]) {
						if (sum > dp2[k]) {
							sum = dp2[k];
							kk = sum;
						}
					}
				}
			}
			else {
				for (int k = j - kk; k < j; k++) {
					dp2[k]++;
					if (aa[j] == aa[k]) {
						if (sum > dp2[k] + 1) {
							sum = dp2[k] + 1;
							kk = sum;
						}
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