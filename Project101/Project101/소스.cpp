#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stdlib.h>
using namespace std;
int main() {
	int n, p, q;
	scanf("%d %d %d", &n, &p, &q);
	int *a = (int *)malloc(4 * (n+1));
	a[0] = 1;
	for (int i = 0; i <= n; i++) {
		if((i%p)*2 >= p && (i%q)*2 >= q)
		a[i] = a[(i / p)-1] + a[(i / q)-1];
		else if ((i%p) * 2 < p && (i%q) * 2 >= q)
			a[i] = a[(i / p)] + a[(i / q) - 1];
		else if ((i%p) * 2 >= p && (i%q) * 2 < q)
			a[i] = a[(i / p) - 1] + a[(i / q)];
		else if ((i%p) * 2 < p && (i%q) * 2 < q)
			a[i] = a[(i / p)] + a[(i / q)];
	}
	printf("%d", a[n]);
}