#include<stdio.h>
#include<stdlib.h>
int main() {
	int n;
	scanf("%d",&n);
	getchar();
	char a[100];
	int sum = 0;
	scanf("%s", a);
	for (int i = 0; i < n; i++) {
		sum += (a[i] - '0');
	}
	printf("%d", sum);
}