#include <stdio.h>
int main() {
	int a ,b, c;
	int i;
	long count1=0, count2=0, count3=0;
	int d[1001], e[1001], f[1001];

	scanf("%d %d %d", &a, &b, &c);
	for (i = 0; i < a; i++) {
		scanf("%d",&d[i]);
		count1 += d[i];
	}
	for (i = 0; i < b; i++) {
		scanf("%d", &e[i]);
		count2 += e[i];
	}
	for (i = 0; i < c; i++) {
		scanf("%d", &f[i]);
		count3 += f[i];
	}
	long long n = (count1 + count2 + count3);
	printf("%lld \n", n);

	int o;
	int y;
	int j = 0;
	if (a <= b && a <= c)
		y = a;
	if (b <= a && b <= c)
		y = b;
	if (c <= b && c <= a)
		y = c;

	for (j = 0; j < a-1; j++) {
		for (i = 0; i < a-1; i++) {
			if (d[i] <= d[i + 1]) {
				o = d[i];
				d[i] = d[i + 1];
				d[i + 1] = o;
			}
		}
	}for (j = 0; j < b-1; j++) {
		for (i = 0; i < b-1; i++) {
			if (e[i] <= e[i + 1]) {
				o = e[i];
				e[i] = e[i + 1];
				e[i + 1] = o;
			}
		}
	}
	for (j = 0; j < c-1; j++) {
		for (i = 0; i < c-1; i++) {
			if (f[i] <= f[i + 1]) {
				o = f[i];
				f[i] = f[i + 1];
				f[i + 1] = o;
			}
		}
	}
	long long yy = 0;
	for (i = 0; i < y; i++) {
		yy += d[i] + e[i] + f[i];
	}
	yy *= 0.1;
	printf("%lld",n- yy);
}
