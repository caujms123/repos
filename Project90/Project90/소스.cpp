#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
	char b[11];
	gets(b);
	printf("%s", &b);
}