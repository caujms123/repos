# include<stdio.h>
int main(void) {
	int w, A;
	int i,o,p,l;
	int k = 0;
	scanf("%d %d", &w, &A);
	int a[5000] = { 0 };
	int b[5000][5000] = { 0 };
	for (i = 0; i < A; i++) {
		scanf("%d", &a[i]);
	}

	for (i = 0; i < A-1; i++)
		for (o = i + 1; o < A ; o++) {
			b[i][o] = a[i] + a[o];
		}

	for (p = 0; p < A-1; p++)
		for (l = p+1; l <A; l++)
			for (i = 0; i < A - 1; i++)
				for (o = p + 1; o < A; o++)
					if (w == b[p][l]+b[i][o]&& (p!=i || l!=o)	) {
						printf("YES");
						return 0;
					}
	printf("NO");
}