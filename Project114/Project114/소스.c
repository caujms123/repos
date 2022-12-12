#include<stdio.h>
int main() {
	int a=0, b=0, c=0, d;
	scanf("%d",&d);
	if (d >= 300) {
		a = d / 300;
		d -= a * 300;
	}
	if (d >= 60) {
		b = d / 60;
		d -= b * 60;
	}
	if (d >= 10) {
		c = d / 10;
	}
	printf("%d %d %d", a, b, c);
}