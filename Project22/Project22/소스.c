# include<stdio.h>
int main(void) {
	int a = 100;
	int * pump;
	pump = &a;
	*pump = 20;
	printf("%d",a);
}