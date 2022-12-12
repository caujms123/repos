#include<stdio.h>
int main(void) {
	int k;
	int j= 0;
	printf("k => ");
	scanf("%d", &k);
	switch (k)
	{
	case 1: case 2: j = 2 * k - 1; break;
	case 3: case 5: j = 3 * k + 1; break;
	case 4: j = 4 * k - 1; break;
	case 6: case 7: case 8: j = k - 2; break;
	default: printf("No case in switch, k = %d", k); return 0;
	}
	printf("j = %d", j);
	return 0;
}