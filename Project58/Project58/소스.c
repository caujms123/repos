# include<stdio.h>
int main() {
	int n;
	int k;
	scanf("%d", &n);
	for (int i = 0;; i++) {
		if (i*(i + 1) / 2 < n && (i + 2)*(i + 1) / 2 >= n) {
			if ((i + 1) % 2 == 0) {
				k = n - (i * (i + 1) / 2);
				printf("%d/%d", k,i+2-k);
				return 0;
			}
			else if ((i+1)%2!=0) {
				k = n - (i * (i + 1) / 2);
				printf("%d/%d",i+2-k ,k);
				return 0;
			}
		}
	}
}