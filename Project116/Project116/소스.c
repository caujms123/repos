# include<stdio.h>
#include<math.h>
int main() {
	int a;
	double b;
	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		scanf("%lf", &b);
		printf("$%.2lf\n", b*0.80);
	}
}