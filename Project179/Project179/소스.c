#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
	char name[101];
	int num;
	char a[100][101];
}group;

int compare(const void *a, const void *b) {
	return strcmp((char*)a, (char*)b);
}

int main() {
	group a[101];
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", a[i].name);
		getchar();
		scanf("%d", &a[i].num);
		for (int j = 0; j < a[i].num; j++) {
			scanf("%s", a[i].a[j]);
		}
		qsort(a[i].a, a[i].num, 101, compare);
	}
	for (int i = 0; i < m; i++) {
		char aa[101];
		int b;
		scanf("%s", aa);
		getchar();
		scanf("%d", &b);
		getchar();
		if (b == 0) {
			for (int i = 0; i < n; i++) {
				if (strcmp(aa, a[i].name) == 0) {
					for (int o = 0; o < a[i].num; o++) {
						printf("%s\n", a[i].a[o]);
					}
					goto aaa;
				}
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				for (int o = 0; o < a[i].num; o++) {
					if (strcmp(aa, a[i].a[o]) == 0) {
						printf("%s\n", a[i].name);
						goto aaa;
					}
				}
			}
		}
	aaa:;
	}
}