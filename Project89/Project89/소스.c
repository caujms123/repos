#include<stdio.h>
int main() {
	int sum=0;
	scanf("%d", &sum);
	if (sum % 4 == 0) {
		if (sum % 400 == 0) {
			printf("1");
		}
		else if (sum % 100 == 0)
			printf("0");
		return 0;
	}
	printf("0");
}