#include<stdio.h>
int main() {
	int a[8];
	int sum[2] = { 0 };
	for (int i = 0; i < 8; i++) {
		scanf("%d", &a[i]);
		if (i < 4) {
			sum[0] += a[i];
		}
		else {
			sum[1] += a[i];
		}
	}
	if (sum[0] >= sum[1])
		printf("%d",sum[0] );
	else {
		printf("%d", sum[1]);
	}
}