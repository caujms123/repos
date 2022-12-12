#include<stdio.h>
int fff(int a) {
	if (a == 1 && a == 2)	return 1;
	return fff(a - 1) + fff(a - 2);
}
int main() {
	int a;
	scanf("%d", &a);
	int k = fff(a);
	printf("%d", k);
}