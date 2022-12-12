#include<stdio.h>
int main() {
	int n;
	int nn;
	int k=0;
	

	for (int i=0;; i++ ) {
		scanf("%d", &n);
		if (n == 0) {
			return 0;
		}
		nn = n + 1;
		if (nn % 2 == 0)
			nn++;
		if (n == 1||n==2) {
			printf("1\n");
			continue;
		}
		for (; nn <= 2 * n; nn+=2) {
			if (nn % 3 == 0 && nn % 5 == 0 && nn % 7 == 0 && nn % 11 == 0 && nn % 13 == 0 && nn % 17 == 0 && nn % 19 == 0 && nn % 23 == 0 && nn % 29 == 0 && nn != 3 && nn != 5 && nn != 7 && nn != 11 && nn != 13 && nn != 17 && nn != 19 && nn != 23 && nn != 29)
			{
				continue;
			}
			if (nn>1000) {
				for (int j = 2; j < nn / 3000; j++) {
					if (nn % j == 0) {
						goto aa;
					}
				}
			}
			k++;
		aa:;
		}
		printf("%d \n", k);
		k = 0;
	}
	return 0;
}