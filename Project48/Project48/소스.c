# include<stdio.h>
int main() {
	int a;
	scanf("%d", &a);
	int k=0;
	for (int i = 0;; i+=k) {
		k++;
		if (a == 1) {
			printf("1");
			return 0;
		}
		if (a >= 1 + (6 * i) + 1 && a <= 1 + 6 * (i+k)) {
			printf("%d", k + 1);
			return 0;
		}
	}
}