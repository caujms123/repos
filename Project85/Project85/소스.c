#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main() {
	int T;
	scanf("%d", &T);
	int *a = (int*)calloc(4,T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &a[i]);
		for (int i=0; i < 81; i++) {
			for(int j=0;j<10;j++)
				if (pow(10,j) <= a[i] && a[i]< pow(10, j)){
				
				}
				a[i] = a[i] + i;
		}
	}
	for (int i = 0; i < T; i++) {
		if (a[i] == 0) printf("-1 ");
		printf("%d ", a[i]);
	}
}