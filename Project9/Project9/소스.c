#include <stdio.h>
int main() {
	int a;
	int b;
	int c;
	int d;
	char e[] = { 0, };
	scanf("%d", &a);
	for (b = 0; b < a; b++)
		scanf("%c",&e[b]);
	printf("%c", sizeof(e));



	return 0;
}