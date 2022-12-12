#include<stdio.h>
int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int k;
		scanf("%d", &k);
		int a[1000];
		int sum = 0;
		for (int j = 0; j < k; j++) {
			scanf("%d", &a[j]);
			sum += a[j];
		}
		int count = 0;
		double mean = (double) sum/k;
		for (int j = 0; j < k; j++) {
			if ((double)a[j] > mean) {
				count++;
			}
		}
		double p = ((double)count / k)*100  ;
		printf("%.3f%\n", p);
	}
}