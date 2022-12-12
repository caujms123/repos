#include<stdio.h>
#include<math.h>
int main() {
	double a, b, c;
	scanf("%lf %lf %lf", &a, &b, &c);
	printf("%.10lf", a*c / b);
}