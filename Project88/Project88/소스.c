#include<stdio.h>
int main() {
	int n[4];
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		scanf("%d", &n[i]);
		sum += n[i];
	}
		printf("%d\n%d",sum/60 ,sum%60);
}