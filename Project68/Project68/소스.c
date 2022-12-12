#include<stdio.h>
int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int k;
		scanf("%d", &k);
		int a[1000];
		int sum=0;
		for (int j = 0; j < k; j++) {
			scanf("%d", &a[i]);
			sum+=a[i];
		}
		int count = 0;
		int mean = sum / k;
		for (int j = 0; j < k; j++) {
			if (a[i] >= mean) {
				count++;
			}
		}
		float p = (float)( (float)count / (float)k ) *100;
		printf("%.3f%\n", p);
	}
}