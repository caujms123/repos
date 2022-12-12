#include<stdio.h>
int main() {
	int k;
	int yy;
	int a[10001];
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
		scanf("%d", &a[i]);
	for(int i=0;i<k-1;i++)
		for(int j=0;j<k-1-i;j++)
			if (a[j] > a[j+1]) {
				yy = a[j+1];
				a[j + 1] = a[j];
				a[j] = yy;
			}
	int b[4];
	b[0]= a[k - 1] * a[k - 2] * a[k - 3];
	b[1]= a[k - 1] * a[k - 2];
	b[2]= a[k - 1] * a[0] * a[1];
	b[3]= a[0] * a[1];
		for (int j = 0; j < 3; j++)
			if (b[j] > b[j + 1]) {
				yy = b[j + 1];
				b[j + 1] = b[j];
				b[j] = yy;
			}
	printf("%d", b[3]);
}