#include<stdio.h>
int main() {
	int a , b , c , d, e, f;
	scanf("%d %d %d %d %d", &a,&b,&c,&d,&e);
	f = e*a;
	if (e <= c) {
		if (f > b) {
			f = b;
		}
	}
	if (e > c) {
		if (f> (b +((e-c)*d))) {
			f = b + ((e - c)*d);
		}
	}
	printf("%d",f);
}