#include<stdio.h>
#include<string.h>
char *a[150000];
int aa[150000];
int main() {
	int i = 0;
	int A, B, C;
	int n;
	scanf("%d %d %d", &A, &B, &C);
	for (i = 0; i < A+B+C; i++) 
		scanf("%s %d",a[i],&aa[i]);
	scanf("%d", &n);
	int sum=0;
	int k = 0;
	char name[10000];
	for (int i = 0; i < n; i++) {
		scanf("%s", name);
		for (int j = 0; j < A + B + C; i++) {
			if (strcmp(name, a[j]) == 0) {
				sum += aa[i];
				break;
			}
			if (sum < 20000 && j >= A){
				printf("No");
				return 0;
			}
			if (sum < 50000 && j >= A + B) {
				printf("No");
				return 0;
			if (j > A + B) {
				k++;
			}
			if (k >= 2) {
				printf("No");
					return 0;
			}
			}
		}
	}
	printf("Okay");
}