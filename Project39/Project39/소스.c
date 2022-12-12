#include<stdio.h>
int main() {
	char s[2000];
	int a;
	int k = 0;
	scanf("%d", &a);
	scanf("%s", s);
	for (int i = 0; i < a; i += 2) {
		if (s[i]==s[i+1]) {
			if (s[i] == 'a') {
				s[i] = 'b';
				k++;
			}
			else {
				s[i] = 'a';
				k++;
			}
		}
	}
	printf("%d\n%s", k, s);
}