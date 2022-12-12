#include<stdio.h>
int main(void) {
	int arry[5] = {0,};
	arry[-1] = 79;
	printf("%d", arry[-1]);
}