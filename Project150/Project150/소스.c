#include<stdio.h>
#define abs(x) ((x>0) ? (x) : -(x))
int main() {
	int nn;
	int n[5000];
	scanf("%d", &nn);
	for (int i = 0; i < nn; i++) {
		scanf("%d",&n[i]);
	}
	int min = 1000000000;
	int a[3];
	int temp;
	for (int i = nn - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (n[j] > n[j + 1]) {
				temp = n[j];
				n[j] = n[j + 1];
				n[j + 1] = temp;
			}
		}
	}
	if (n[0] >= 0) {
		printf("%d %d %d", n[0], n[1], n[2]);
		return 0;
	}
	else if (n[nn - 1] <= 0) {
		printf("%d %d %d", n[nn - 3], n[nn - 2], n[nn - 1]);
		return 0;
	}
	if (n[1] >= 0) {
		if (abs(n[0] + n[1] + n[2]) > abs(n[1]+n[2]+n[3])) {
			printf("%d %d %d", n[1],n[2] , n[3]);
			return 0;
		}
		else {
			printf("%d %d %d", n[0] , n[1] , n[2]);
			return 0;
		}
	}
	if (n[nn-2] <= 0) {
		if (abs(n[nn-3] + n[nn-2] + n[nn-1]) > abs(n[nn-4] + n[nn-3] + n[nn-2])) {
			printf("%d %d %d", n[nn - 4] , n[nn - 3] , n[nn - 2]);
			return 0;
		}
		else {
			printf("%d %d %d", n[nn - 3] , n[nn - 2] , n[nn - 1]);
			return 0;
		}
	}
	int point=0;
	for (point = 0;; point++) {
		if (n[point] >= 0) {
			break;
		}
	}
	//printf("\n%d\n", point);
	for (int i = point - 1; i > 0; i--) { //음수 2개 양수 1개
		for (int j = point - 2; j >= 0; j--) {
			for (int k = point; k < nn; k++) {
				//printf("zz");
				if (n[i] + n[j] + n[k] == 0) {
					//printf("%d %d %d", n[j], n[i], n[k]);
					return 0;
				}
				//printf("zz");
				//printf("%d\n", abs(n[i] + n[j] + n[k]));
				if (min >= abs(n[i] + n[j] + n[k])) {
					min = abs(n[i] + n[j] + n[k]);
					a[0] = n[j], a[1] = n[i], a[2] = n[k];
				}
				else {
					continue;
				}
			}
		}
	}
	for (int i = 0; i <= nn-1; i++) { // 양수 2개 음수 1개
		for (int j = i+1; j <= nn; j++) {
			for (int k = point -1; k ==0; k--) {
				if (n[i] + n[j] + n[k] == 0) {
					printf("%d %d %d", n[k], n[j], n[i]);
					return 0;
				}
				if (min >= abs(n[i] + n[j] + n[k])) {
					min = abs(n[i] + n[j] + n[k]);
					a[0] = n[k], a[1] = n[j], a[2] = n[i];
				}
				else {
					continue;
				}
			}
		}
	}

	int nnn[3] = { abs(n[point] +n[point+1] + n[point + 2]), abs(n[point - 1] + n[point - 2] + n[point - 3]), abs(a[0] + a[1] + a[2])};
	printf("%d %d %d", nnn[0], nnn[1], nnn[2]);
	if (nnn[0] <= nnn[1] && nnn[0] <= nnn[2]) printf("%d %d %d",n[point] , n[point+1] , n[point + 2]); return 0;
	if(nnn[1] <= nnn[0] && nnn[1] <= nnn[2]) printf("%d %d %d", n[point-3], n[point - 2], n[point -1]); return 0;
	if(nnn[2] <= nnn[0] && nnn[2] <= nnn[1]) printf("%d %d %d",a[0] , a[1] , a[2]); return 0;
}