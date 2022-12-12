#include<stdio.h>
typedef struct {
	int count;
	int n[1001];
}point;
point p[1001];
void count(int,int);
int main() {
	int a, b;
	int n[1001] = {0,};
	scanf("%d %d", &a, &b);
	int x, y;
	for (int i = 0; i < b; i++) {
		scanf("%d %d", &x, &y);
		p[x].n[y] = 1;
	}
	for (int i = 1; i <= a; i++) {
		count(i,0);
	}
	for (int i = 1; i <= a; i++) {
		printf("%d ", p[i].count + 1);
	}
}
void count(int pp,int count1) {
	for (int i = 1; i < 1001; i++) {
		if (p[pp].n[i] == 1) {
			count(i, count1 + 1);
		}
		if (p[pp].count < count1) {
			p[pp].count = count1;
		}
	}
}