# include<stdio.h>
int main() {
	int a;
	int count=0;
	scanf("%d", &a);
	while (1) {
		if (a == 1) {
			printf("%d", count);
			return 0;
		}
		if (a % 3 == 0) {
			a = a / 3;
			count++;
			continue;
		}
		if ((a - 1) % 3 == 0) {
			if (a % 4 == 0) {
				a = a / 4;
				count+=2;
				continue;
			}
			a= a - 1;
			count++;
			continue;
		}
		if (a % 2 == 0) {
			a= a / 2;
			count++;
			continue;
		}
		a = a - 1;
		count++;
	}
}