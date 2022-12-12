#include<stdio.h>
int c[100000] = { 0 };
int main() {
	int t;
	scanf("%d", &t);
	int a, b;
	int count = 0;
	for (int i = 0; i < t; i++) {
		count = 0;
		c[0] = 1;
		scanf("%d %d", &a, &b);
		c[a] = 1, c[b] = 1;
		for (int j = 1; j < 100000; j++) {
			if (c[j - a] == 1 || c[j - b] == 1) {
				c[j] = 1;
				count++;
				if (count > a || count > b) {
					printf("Finite\n");
					goto aaa;
				}
				continue;
			}
			count = 0;
		}
		printf("Infinite\n");
	aaa:;
		for (int k= 0; k < 100000; k++) {
			c[k] = 0 ;
		}
	}

}
