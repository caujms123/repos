#include<stdio.h>
#include<stdlib.h>
int n, m, v;
int o[1000];
int que[1000];
int pp=0;
typedef struct aaa{
	int num;
	int o[1001];
	int check;
}aaa;
void dfs(aaa* a, int h) {
	a[h].check=0;
	printf("%d ", a[h].num);
	for (int i = 1; i <= n; i++) {
		if (a[h].o[i] == 1) {
			if (a[i].check == 1) {
				dfs(a, i);
				a[i].check = 0;
			}
		}
	}
	a[h].check = 1;
	return;
}
void pr(aaa* a, int h) {
	if (a[h].check != 0) {
		printf("%d ", a[h].num);
	}
	a[h].check = 0;
	for (int i = 1; i <= n; i++) {
		if (a[h].o[i] == 1) {
			if (a[i].check == 1) {
				printf("%d ", a[i].num);
				a[i].check = 0;
				que[pp++]=i;
				o[i] = 1;
			}
		}
	}
}
int main() {
	scanf("%d %d %d",&n,&m,&v);
	aaa * a = (aaa *)malloc(sizeof(aaa)*(n+1));
	int x, y;
	for (int i = 0;i< m;i++) {
		scanf("%d %d",&x,&y);
		a[x].num = x;
		a[x].o[y] = 1;
		a[x].check = 1;
		a[y].num = y;
		a[y].o[x] = 1;
		a[y].check = 1;
	}
	a[v].check = 1;
	a[v].num = v;
	dfs(a,v);
	for (int i = 1; i <= n; i++) {
		a[i].check = 1;
	}
	printf("\n");
	int yyy=0;
	pr(a, v);
	while (1) {
		if (que[yyy] == 0) {
			return;
		}
		pr(a, que[yyy++]);
	}
}