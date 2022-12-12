# include<stdio.h>
int main(void) {
	int w, A;
	int i, o, p, l;
	int k = 0;
	scanf("%d %d", &w, &A);
	int a[5000] = { 0 };
	int b[2500] = { 0 };
	int c[2500] = { 0 };
	int d[2500] = { 0 };
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
	for (i = 0; i < k - 1; i++)
		for (o = i + 1; o < k; o++)
			if (w = b[i] + b[o]) {
				if (c[o] != d[i] && c[i] != d[o]&& c[o] != c[i] && d[o] != d[i]) {
					printf("YES");
					return 0;
				}
			}
	printf("NO");

}