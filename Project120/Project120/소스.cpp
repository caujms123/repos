#include<stdio.h>
int main() {
	int a;
	scanf("%d", &a);
	for (int i = 0; i < a-1; i++) {
		for (int k = 0; k < a-i-1; k++) {
			printf(" ");
		}
		for (int j = 0; j < i*2+1; j++) {
			printf("*");
		}
		printf("\n");
	}
	for (int i = 0; i < a; i++) {
		for (int k = 0; k < i; k++) {
			printf(" ");
		}
		for (int j = 0;j<2*a-(1+i*2);j++) {
			printf("*");
		}
		printf("\n");
	}
}