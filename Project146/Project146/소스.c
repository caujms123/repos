#include<stdio.h>
#include<stdlib.h>
int main() {
	int a, b, aa, bb;
	int n[10000];
	int nn[10000];
	scanf("%d %d %d %d", &a, &b, &aa, &bb);
	for (int i = 0; i < 10000; i++) {
		n[i] = aa + i * a;
		nn[i] = bb + i * b;
	}
	for (int i = 0; i < 10000; i++) {
		for (int j = 0; j < 10000; j++) {
			if (n[i] == nn[j]) {
				printf("%d", n[i]);
				return 0;
			}
		}
	}
	printf("-1");
}