 
#include<stdio.h>
#include<string.h>
char a[150000][21];
char aaa[150000][21];
int aa[150000];
int main() {
	int sum1=0;
	int count1 = 0, count2 = 0;
	int A, B, C;
	int n;
	int sum = 0;
	scanf("%d %d %d", &A, &B, &C);
	for (int i = 0; i < A + B; i++) {
		scanf("%s", a[i]);
		scanf("%d", &aa[i]);
	}
	for (int i = A+B; i < A+B+C; i++) {
		scanf("%s", a[i]);
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", aaa[i]);
		for (int j = A + B; j < A + B + C; j++) {
			if (strcmp(a[j], aaa[i]) == 0) {
				count2++;
				if (count2 > 1) {
					printf("No");
					return 0;
				}
			}
		}
	}
	if (count2 == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < A + B; j++) {
				if (strcmp(a[j], aaa[i]) == 0) {
					if (j >= A && j <= A + B - 1) {
						count1 = 1;
					}
					if (j <= A - 1) {
						sum1 += aa[j];
					}
					sum += aa[j];
					if (sum > 50000&&sum1>20000) {
						printf("Okay");
						return 0;
					}
				}
			}
		}
		if (sum1 < 20000)
			if (count1 == 1) {
				printf("No");
				return 0;
			}
			else if (sum < 50000) {
					printf("No");
					return 0;
			}
		printf("Okay");
	}
	else if (count2 == 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < A + B; j++) {
				if (strcmp(a[j], aaa[i]) == 0) {
					if (j >= A && j <= A + B - 1) {
						count1 = 1;
					}
					if (j <= A - 1) {
						sum1 += aa[j];
					}
					if (sum1 > 20000) {
						printf("Okay");
						return 0;
					}
				}
			}
		}
		if (sum1 < 20000)
			if (count1 == 1) {
				printf("No");
				return 0;
			}
		printf("Okay");
	}
}
