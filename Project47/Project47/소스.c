#include<stdio.h>
int main() {
	int a[100];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int p=0;
	int q = 0;
	for (int i = 0; i < n; i++){
		if (a[i] == 1) {
			continue;
		}
		for (int j = 2; j < a[i]; j++) {
			if (a[i] % j == 0)
				break;
			else if (a[i] % j != 0)
				q++;
		}
		if (q == a[i] - 2)
			p++;
		q = 0;
	}
	printf("%d", p);
}