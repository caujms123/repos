#include<stdio.h>
int main() {
	int a,b,c;
	scanf("%d %d %d", &a,&b,&c);
	if (b >= c) {
		printf("%d",c+(a-b));
	}
	else {
		printf("%d", b+(a-c));
	}
}