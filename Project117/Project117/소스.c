#include<stdio.h>
#include<math.h>
int main() {
	long double a;
	scanf("%Lf", &a);
	long double b = (sqrt(3)*a*a) / 4;
	printf("%.9Lf", b);
}