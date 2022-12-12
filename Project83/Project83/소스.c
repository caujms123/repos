#include<stdio.h>
#include<stdlib.h>
int main() {
	int n;
	long long k = 0;
	long long p = 1;
	long long q = 1;
	scanf("%d",&n);
	for (int i = 0; n-2*i>=0; i++) {
		if ((n-2*i)>=i) {
			for (int j = n - 2 * i + 1; j <= n - i; j++) {
				p *= j;
				p %= 10007;
			}
			for (int j = 1; j <= i; j++) {
				q *= j;
				q %= 10007;
			}
		}
		else if ((n-2*i)<i) {
			for (int j = i+1; j <= n - i; j++) {
				p *= j;
				p %= 10007;
			}
			for (int j = 1; j <= n-2*i; j++) {
				q *= j;
				q %= 10007;
			}
		}
		k += (p / q)%10007;
		q = 1;
		p = 1;
	}
	printf("%d", k%10007);
}