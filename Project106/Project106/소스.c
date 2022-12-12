#include<stdio.h>
int main() {
	int a[5];
	for(int i=0;i<5;i++)
	scanf("%d", &a[i]);
	if (a[1] / a[3] >= a[2] / a[4]) {
		if (a[1]%a[3]== 0) {
			printf("%d", a[0] - a[1] / a[3]);
		}
		else {
			printf("%d", a[0] - (a[1] / a[3]+1));
		}
	}
	else {
		if (a[2] % a[4] == 0 ) {
			printf("%d", a[0] - (a[2] / a[4] + 1));
		}
		else {
			printf("%d", a[0] - a[2] / a[4]);
		}
	}
}
