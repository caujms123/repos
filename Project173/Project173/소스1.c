# include<stdio.h>
int n;
int main() {
	int a[100];
	int b[100];
	int c[100];
	int answer[1000] = { 0 };
	answer[0] = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		scanf("%d", &b[i]);
		scanf("%d", &c[i]);
	}
	int count = 0;
	for (int i = 123; i < 1000; i++) {
		int aa, bb, cc;
		aa = i / 100;
		bb = (i % 100) - (i % 10);
		cc = (i % 10);
		if (aa == bb || bb == cc || aa == cc) {
			continue;
		}
		count++;
		for (int j = 0; j < n; j++) {
			int aaa, bbb, ccc;
			int s = 0, ball = 0;
			aaa = a[j] / 100;
			bbb = (a[j] % 100) - (a[j] % 10);
			ccc = (a[j] % 10);
			if (aa == aaa) s++;
			if (bb == bbb) s++;
			if (cc == ccc) s++;
			if (aa == bbb) ball++;
			if (bb == ccc) ball++;
			if (cc == aaa) ball++;
			if (aa == ccc) ball++;
			if (bb == aaa) ball++;
			if (cc == bbb) ball++;
			if (s != b[j] || ball != c[j]) {
				count--;
				break;
			}
		}
	}
	printf("%d", count);
}