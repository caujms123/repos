#include<stdio.h>
# define abs(x)   (x>0 ?  (x) : (-(x))) 
int main() {
	int a;
	scanf("%d", &a);
	for (int i = 0; i < 2 * a - 1; i++) {
		for (int j = 0;j < abs(a-1-i);j++) {
			printf(" ");
		}
		for (int j = 0; j < a - abs(a-1 - i); j++) {
			printf("*");
		}
		if(i<2*a-2)
		printf("\n");
	}
}