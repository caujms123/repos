#include<stdio.h>
int main() {
	char *d[101];
	for(int i=0;i<4;i++)
		d[i]=gets();
	for(int i=0;i<4;i++)
		printf("%s\n", d[i]);
}