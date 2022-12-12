#include<stdio.h>
int main() {
	int a;
	int n[50];
	int b;
	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		scanf("%d", &n[i]);
	}
	scanf("%d",&b);
	for (int i = 0; i < a; i++) {
		if (n[i] == b) {
			printf("0");
			return 0;
		}
	}
	int temp;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a - i-1; j++) {
			if (n[j] > n[j + 1]) {
				temp = n[j];
				n[j] = n[j + 1];
				n[j + 1] = temp;
			}
		}
	}
	/*for (int i = 0; i < a; i++) {
		printf("%d ", n[i]);
	}
	*/
	int sum = 0;
	int i;
	if (b < n[0]) {
		for (int j = 1; j < b; j++) {
			sum += n[0] - b;
		}
		sum += n[0] - b - 1;
		printf("%d", sum);
		return 0;
	}
	for (i = 0; i < a-1; i++) {
		if (b > n[i] && b < n[i + 1]) {
			for (int j = n[i] + 1; j < b; j++) {
				sum += n[i + 1] - b;
			}
			break;
		}
	}
	//printf("%d", n[i+1]);
	sum += n[i+1] -b - 1;
	printf("%d",sum);
}