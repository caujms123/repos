#include <stdio.h>
#include<string.h>
int main() {
	int count = 0;
	char q;
	char stringy[1000000];
	scanf("%s", stringy);
	scanf("%c", &q);
	int s = strlen(stringy);
	for (int i = 0; i < s; i++)
		if (strcmp(stringy[i], q) == 0)
			count++;
	printf("%d", count);
	return 0;
}

