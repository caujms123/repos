#include <stdio.h>
#include <string.h>

int main() {
	int n;
	int d=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char c[101];
		int *b=(int*)calloc(4,26);
		scanf("%s", c);
		int k=strlen(c);
		for (int p = 0;p<k;p++) {
			int m = c[p] - 'a';
			int m1 = c[p - 1] - 'a';
			if(c[p]!=c[p-1]&&p>0){
				b[m1] = -1;
			}
			if (b[m] == -1) {
				goto aaa;
			}
		}
			d++;
		aaa: free(b);
	}
	printf("%d", d);
}