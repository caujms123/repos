#include<stdio.h>
# define abs(x) (x>0 ? x: (-(x)))    // 이상 없음
int dd[100000000] = { 0 };
int P[500000];
int Q[500000];
int main() {
	int d = 0;
	int n, m;
	int c1, c2;
	int pp;
	scanf("%d %d %d %d", &n, &m, &c1, &c2);
	for (int i = 0; i < n; i++) {
		scanf("%d", &P[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &Q[i]);
	}
	for (int i = 0; i < n - 1; i++)						// 이상 없음
		for (int j = 0; j < n - 1 - i; j++)
			if (P[j] > P[j + 1]) {
				pp = P[j];
				P[j] = P[j + 1];
				P[j + 1] = pp;
			}
	for (int i = 0; i < m - 1; i++)                      // 이상 없음
		for (int j = 0; j < m - 1 - i; j++)
			if (Q[j] > Q[j + 1]) {
				pp = Q[j];
				Q[j] = Q[j + 1];
				Q[j + 1] = pp;
			}
	if (n == 1 && m==1) {
		printf("%d 1", abs(Q[0] - P[0])+ abs(c1 - c2));
			return 0;
	}
	if (n == 1 ) {
		d = abs(Q[0] - P[0]);
		for (int i = 1; i < m; i++) {
			if (d > abs(Q[i] - P[0])) {
				d = abs(Q[i] - P[0]);
			}
			else if (d == abs(Q[i] - P[0])) {
				dd[d] += 2;
				break;
			}
			else if (d < abs(Q[i] - P[0])) {
				dd[d]++;
				break;
			}
			if (i == m - 1) {
				dd[d]++;
				break;
			}
		}
	}
	if (m == 1) {
		d = abs(Q[0] - P[0]);
		for (int i = 1; i < n; i++) {
			if (d > abs(Q[0] - P[i])) {
				d = abs(Q[0] - P[i]);
			}
			else if (d == abs(Q[0] - P[i])) {
				dd[d] += 2;
				break;
			}
			else if (d < abs(Q[0] - P[i])) {
				dd[d]++;
				break;
			}
			if (i == n - 1) {
				dd[d]++;
				break;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		d = abs(Q[i] - P[0]);							// 이상 없음
		for (int j = 1; j < n; j++) {
			if (d > abs(Q[i] - P[j])) {
				d = abs(Q[i] - P[j]);
			}
			else if (d == abs(Q[i] - P[j])) {
				dd[d] += 2;
				break;
			}
			else if (d < abs(Q[i] - P[j])) {
				dd[d]++;
				break;
			}
			if (j == n - 1) {
				dd[d]++;
				break;
			}
		}
	}
	int i;
	for (i = 0;; i++) {
		if (dd[i] != 0)
			break;
	}
	printf("%d %d", i + abs(c1 - c2), dd[i]);     // abs(c1-c2) 이상 없음
	return 0;
}