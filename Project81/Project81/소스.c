#include<stdio.h>
int main() {
	int t;
	scanf("%d", &t);
	int a, b;
	int m = 0;
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &a, &b);
		for (int m = 2; m < 10000; m++)
			if (a%m == 0 || b % m == 0) {
				printf("Infinite\n");
				goto aaa;
			}
		printf("Finite\n");
	aaa:;
	}

}
