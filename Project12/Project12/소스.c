#include<stdio.h>
int main(void) {
	long a,i;
	long b[100000];
	scanf("%ld", &a);
	for (i = 0; i < a; i++) {
		scanf("%ld", &b[i]);
		b[i] = ((b[i]/3) * (b[i]/3 + 1)*3 + (b[i]/7) * (b[i]/7 + 1)*7 - (b[i]/21) * (b[i]/21 + 1)*21)/2;
	}
	for (i = 0; i < a; i++)
		printf("%ld \n",b[i]);
	return 0;
}