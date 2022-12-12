#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
	int a;
	int b[20];
	int Y=0, M=0;
	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 0;i<a; i++) {
		for (int j = 0;; j++) {
			if (b[i] < (j + 1) * 30 && b[i] >= (j) * 30) {
				Y += 10 * (j + 1);
				break;
			}
		}
	}
	for (int i = 0;i<a; i++) {
		for (int j = 0;; j++) {
			if (b[i] < (j + 1) * 60 && b[i] >= (j) * 60) {
				M += 15 * (j + 1);
				break;
			}
		}
	}
	if (Y < M) {
		printf("Y %d", Y);
	}
	else if(M < Y) {
		printf("M %d", M);
	}
	else {
		printf("Y M %d", M);
	}
}