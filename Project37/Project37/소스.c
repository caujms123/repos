#include<stdio.h>
int main() {
	char s[10005];
	int a = 0;
	int e=0, o=0;
	int k;
	int c=1;
	int i=0;
	scanf("%d", &a);
	scanf("%s", s);
	for (i=0;i<a;i++) {
		if (s[i] == 'a')
			e++;
		else if (s[i] == 'b')
			o++;
	}
	if (e == o) {
		printf("0\n");
		printf("%s", s);
	}
	if (e > o) {
		k = (e - o) / 2;
		for (i = 0;; i++) {
			if (s[i] == 'a'&&c <= k){
				s[i] = 'b';
				c++;
			}
			else break;
		}
			printf("%d\n%s", k, s);
	}


	else if (o > e) {
		k = (o - e) / 2;
		for (i = 0;; i++) {
			if (s[i] == 'b'&&c <= k) {
				s[i] ='a';
				c++;
			}
			else break;
		}
		printf("%d\n%s", k, s);
	}
}