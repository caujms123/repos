#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int x;
# define abs(x) ((x)>0? x:(-(x)))
int main(int argc, char *argv[]) {
	int k = 0;
	int a[1000];

	for (int i = 1; i < argc; i++)
		a[i] = atoi("argv[i]");

	if ((strcmp(argv[0], "-a")) == 0)
		for (int i = 1; i < argc; i++)
			a[i] = abs(a[i]);
	for (int i = 1; i < argc; i++)
		k += a[i];
	printf("%d", k);
}