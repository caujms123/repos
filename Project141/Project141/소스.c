#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	if (n == 1) {
		printf("*");
		return 0;
	}
	for(int i=0;i<4*n-3;i++)
	printf("*");
	printf("\n");
	for (int i = (4 * n - 1) / 2-2 ; i>=0 ; i--) {
		if (i % 2 == 0) {
			for (int j = 0; j < (4 * n - 3) / 4 - (i / 2); j++) {
				printf("*");
				printf(" ");
			}
			for (int j = 0; j < 1 + 2 * i+1; j++) {
				printf("*");
			}
			for (int j = 0; j < (4 * n - 3) / 4 - (i / 2); j++) {
				printf("*");
				printf(" ");
			}
			printf("\n");
		}
		else {
			for (int j = 0; j < (4 * n - 3) / 4 - (i / 2); j++) {
				printf("*");
				printf(" ");
			}
			for (int j = 0; j < 1 + 2 * i+1; j++) {
				if(i!=(4 * n - 1) / 2 - 2)printf(" ");
			}
			for (int j = 0; j < (4 * n - 3) / 4 - (i / 2)-1; j++) {
				printf("*");
				printf(" ");
			}
			printf("\n");
		}
	}

	for (int i = 0; i < (4*n - 3)/2+1; i++) {
		printf("*");
		printf(" ");
	}
	printf("\n");
	for (int i = 0;i<(4*n-1)/2;i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < (4 * n - 3)/4-(i/2); j++){
				printf("*");
				printf(" ");
			}
			for (int j = 0; j < 1 + 2 * i; j++) {
				printf("*");
			}
			printf(" ");
			for (int j = 0; j < (4 * n - 3) / 4 - (i / 2); j++) {
				printf("*");
				if(i!=(4*n-1)/2-1)printf(" ");
			}
			printf("\n");
		}
		else {
			for (int j = 0; j < (4 * n - 3) / 4 - (i / 2); j++) {
				printf("*");
				printf(" ");
			}
			for (int j = 0; j < 1 + 2 * i-1; j++) {
				printf(" ");
			}
			for (int j = 0; j < (4 * n - 3) / 4 - (i / 2); j++) {
				printf("*");
				printf(" ");
			}
			printf("\n");
		}
	}
}