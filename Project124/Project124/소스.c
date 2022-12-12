#include<stdio.h>
int main() {
	int a;
	scanf("%d", &a);
	int  b = a;
	int k = 2 * a - 1;
	int c = 0;
	for (int i = 0; i < 2 * a - 1; i++) {
		if (i< a) {
			for (int j = 0; j < i; j++)
				printf(" ");
			for (int j = 0; j < k; j++)
				printf("*");
			k -= 2;
		}
		else {
			b--;
			k += 2;
			for (int j = 0; j < b-1; j++)
				printf(" ");
			for (int j = 0; j < k+2; j++)
				printf("*");

		}
		printf("\n");
	}
}