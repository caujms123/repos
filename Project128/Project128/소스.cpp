#include<stdio.h>
int main() {
	while(1) {
		int b, c;
		int k = scanf("%d %d", &b, &c);
		if (k == EOF) {
			return 0;
		}
		printf("%d\n", b + c);
	}
}