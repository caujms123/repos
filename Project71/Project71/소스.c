#include<stdio.h>
int main() {
	unsigned long long a, b;
	a = 545 * 923 * 400 * 857;
	b =	975 * 215 * 18 * 324;
	int bb = b % 943;
	int aa = a % 943;
	printf("%d", (aa*bb)%943);
}