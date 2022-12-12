#include<stdio.h>
int main() {
	int N;
	long M;
	long H[100] = {0};
	long u[100][100][100] = {0};
	long i;
	long j;
	long k;
	long p=0;

	scanf("%d %ld",&N,&M);
	for (i = 0; i < N; i++) 
		scanf("%ld", &H[i]);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				if (i != j && j != k && k != i) {
					u[i][j][k] = H[i] + H[j] + H[k];
				}
			}
		}
	}

	k = u[0][0][0];
	for (j = 0; j < N; j++) {
		if (k < u[j])
			k = u[j];
	}
	printf("%ld", k);
	return 0;
}