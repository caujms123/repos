#include<stdio.h>
int main() {
	int a[4];
	for(int i=0;i<4;i++)
		scanf("%d", &a[i]);
	if (a[0] + a[3] - a[1] - a[2] >= 0) {
		printf("%d", a[0] + a[3]-a[1]-a[2]);
	}
	else {
		printf("%d", (-1)*(a[0] + a[3] - a[1] - a[2]));
	}
}