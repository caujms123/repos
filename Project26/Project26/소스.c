# include<stdio.h>
int main(void) {
	int w, A;
	int i, o, p, l;
	int k = 0;
	scanf("%d %d", &w, &A);
	int a[5000] = { 0 };
	int b[52500];
	int c[52500];
	int d[52500];
	for (i = 0; i < A; i++) {
		scanf("%d", &a[i]);
	}

	for (i = 0; i < A - 1; i++)
		for (o = i + 1; o < A; o++) {
			b[k] = a[i] + a[o];
			c[k] = i;
			d[k] = o;
			k++;
		}
	for (i = 0; i < k ; i++)
		for (o = i + 1; o < k+1; o++)
			if (w == b[i] + b[o] && c[o] != d[i] && c[i] != d[o] && c[o] != c[i] && d[o] != d[i]) {
				printf("YES \n");
			}
	printf("NO");

}