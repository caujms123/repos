#include <stdio.h>
#include<string.h>
int main() {
	int count = 0;
	char q;
	char str[1000];
	scanf("%s ", str);
	scanf("%c", &q);
	int s = strlen(str);
	for (int i = 0; i < s; i++) {
		if (strcmp(*str, q) == 0) {
			count++;
		}
		str++;
	}
	printf("%d", count);
	
	return 0;
}

