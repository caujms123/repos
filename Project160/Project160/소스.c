#include<stdio.h>
typedef struct {
	int count;
	int n[1001];
	int check;
	int dp;
}point;
point p[1001];
void count(int, int);
int main() {
	int a, b;
	int n[1001] = { 0, };
	scanf("%d %d", &a, &b); // a ��ü���� ,b �������� ����

	int x, y;
	for (int i = 0; i < b; i++) { // �Է�
		scanf("%d %d", &x, &y);
		p[x].n[y] = 1;
		p[x].check = 1;
	}
	for (int i = 1; i <= a; i++) { // count �ϱ�
		count(i, 0);
	}
	for (int i = 1; i <= a; i++) {
		printf("%d ", p[i].count + 1);
	}
}
void count(int pp, int count1) { 
	if (p[pp].check == 0) {
		if (p[pp].count < count1) {
			p[pp].count = count1;
		}
		return;
	}
	int check = 0;
	if (p[pp].count < count1) {
		p[pp].count = count1;
		p[pp].dp = 1;
		check = 1;
	}
	if ((p[pp].dp ==1) && (check !=1)) {
		return;
	}
	for (int i = 1; i < 1001; i++) {
		if (p[pp].n[i] == 1) {
			count(i, count1 + 1);
		}
	}
}