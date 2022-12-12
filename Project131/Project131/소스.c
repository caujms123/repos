#include<stdio.h>
#include<stdlib.h>
int main() {
	char a[5];
	for (int i = 0; i < 3; i++) {
		gets(a);
		printf("read %d :%s", i + 1, a);
	}
}