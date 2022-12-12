#include<stdio.h>
#include<math.h>
int main() {
	int a, b, c, d, e, f;
	scanf("%d %d %d %d %d %d", &a,&b,&c,&d,&e,&f);
	if (a == c)
		printf("%d ", e);
	else if (a == e)
		printf("%d ", c);
	else if (c == e)
		printf("%d ", a);
	if (b == d)
		printf("%d", f);
	else if (b == f)
		printf("%d", d);
	else if (f == d)
		printf("%d", b);
}