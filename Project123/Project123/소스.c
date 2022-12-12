#include<stdio.h>
int main() {
	int a, b, c;
	int d, e;
	scanf("%d %d %d", &a, &b, &c);
	if (a%c == 0) {
		d = a / c;
	}
	else {
		d = a / c + 1;
	}
	if (b%c == 0) {
		e = b / c;
	}
	else {
		e = b / c + 1;
	}
	printf("%d", d*e);
}