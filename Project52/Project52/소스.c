#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
int static compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}
int P[500000] = { 0 };
int Q[500000] = { 0 };
# define abs(x) (x>0 ? x: (-(x)))    // 이상 없음
int main() {
	int aa = 0;
	int d = 0;
	int n, m;
	int c1, c2;
	scanf("%d %d %d %d", &n, &m, &c1, &c2);
	for (int i = 0; i < n; i++) {
		scanf("%d", &P[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &Q[i]);
	}
	qsort(P, n, sizeof(int), compare);
	qsort(Q, m, sizeof(int), compare);
	int kk=INT_MAX;
	if (n == 1 && m == 1) {
		printf("%d 1", abs(Q[0] - P[0]) + abs(c1 - c2));
		return 0;
	}
	else if (n == 1) {
		d = abs(Q[0] - P[0]);
		for (int i = 1; i < m; i++) {
			if (d > abs(Q[i] - P[0])) {
				d = abs(Q[i] - P[0]);
			}
			else if (d == abs(Q[i] - P[0])) {
				if (kk > d) {
					kk = d;
				}
				else if (kk < d)
					aa = 0;
				else if (kk == d)
					aa += 2;
				break;
			}
			else if (d < abs(Q[i] - P[0])) {
				if (kk > d) {
					kk = d;
					aa=1;
				}
				else if (kk < d)
					aa = 0;
				else if (kk == d)
					aa++;
				break;
			}
			if (i == m - 1) {
				if (kk > d) {
					kk = d;
					aa=1;
				}
				else if (kk < d)
					aa = 0;
				else if (kk == d)
					aa++;
				break;
			}
		}
	}
	else if (m == 1) {
		d = abs(Q[0] - P[0]);
		for (int i = 1; i < n; i++) {
			if (d > abs(Q[0] - P[i])) {
				d = abs(Q[0] - P[i]);
			}
			else if (d == abs(Q[0] - P[i])) {
				if (kk > d) {
					kk = d;
				}
				else if (kk < d)
					aa = 0;
				else if (kk == d)
					aa += 2;
				break;
			}
			else if (d < abs(Q[0] - P[i])) {
				if (kk > d) {
					kk = d;
					aa=1;
				}
				else if (kk < d)
					aa = 0;
				else if (kk == d)
					aa++;
				break;
			}
			if (i == n - 1) {
				if (kk > d) {
					kk = d;
					aa=1;
				}
				else if (kk < d)
					aa = 0;
				else if (kk == d)
					aa++;
				break;
			}
		}
	}
	int y = 1;
	for (int i = 0; i < m; i++) {
		d = abs(Q[i] - P[0]);							// 이상 없음
		for (int j = y; j < n; j++) {
			if (d > abs(Q[i] - P[j])) {
				d = abs(Q[i] - P[j]);
			}
			else if (d == abs(Q[i] - P[j])) {
				if (kk > d) {
					kk = d;
				}
				else if (kk < d)
					aa = 0;
				else if (kk == d)
					aa += 2;
				if (j - 1 != 0)
					y = j - 1;
				break;
			}
			else if (d < abs(Q[i] - P[j])) {
				if (kk > d) {
					kk = d;
					aa=1;
				}
				else if (kk < d)
					aa = 0;
				else if (kk == d)
					aa++;
				if (j - 1 != 0)
					y = j - 1;
				break;
			}
			if (j == n - 1) {
				if (kk > d) {
					kk = d;
					aa=1;
				}
				else if (kk < d)
					aa = 0;
				else if (kk == d)
					aa++;
				break;
			}
			aa = 0;
		}
	}
	printf("%d %d", kk + abs(c1 - c2), aa);     // abs(c1-c2) 이상 없음
	return 0;
}