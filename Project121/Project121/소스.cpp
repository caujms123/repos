#include<stdio.h>
int main() {
	int a;
	int b[50];
	int c[50];
	int k[50];
	scanf("%d", &a);
	for(int i=0;i<a;i++){
		scanf("%d %d",&b[i],&c[i]);
		k[i] = 1;
	}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			if (b[i] > b[j]) {
				if (c[i] > c[j]) {
					k[j]++;
				}
			}
		}
	}
	for (int i = 0; i < a; i++) {
		printf("%d ",k[i]);
	}
}