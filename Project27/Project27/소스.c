# include <stdio.h>
int main(void) {
	int w, A;
	int a[5000] = { 0 };
	int b[1250] = { 0 };
	int c[1250] = { 0 };
	int d[1250] = { 0 };
	int i, j, k = 0;
	scanf("%d %d", &w, &A);
	for (i=0;i<A;i++) {
		scanf("%d", &a[i]);
	}
	for(i=0;i<A-1;i++)
		for (j = i + 1; j < A; j++) {
			b[k] = a[i] + a[j];
			c[k] = i; d[k] = j;
			k++;
		}
	for(i=0;i<k-1;i++)
		for(j=i+1;j<k;j++)
			if (b[i]== w - b[j] && c[i] != c[j] && d[i] != c[j] && c[i] != d[j] && d[i] != d[j]) {
				printf("%d %d %d %d \n", c[i], c[j], d[i], d[j]);
				printf("YES \n");
				
			}
	printf("NO");
	return 0;
}