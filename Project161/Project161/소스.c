#include<stdio.h>
#include<stdlib.h>
int main() {
	int n;
	scanf("%d", &n);
	int max = -2000000;
	int min = 2000000;
	for (int i = 0; i < n; i++) {
		int r;
		scanf("%d", &r);
		if (r < min) {
			min = r;
		}
		if (r > max) {
			max = r;
		}
	}
	printf("%d %d", min, max);
}