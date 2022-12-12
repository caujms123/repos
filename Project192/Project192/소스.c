#include<stdio.h>
void change(int *a);
int main() {
	int a[10];
	for (int i = 0; i < 10; i++) {
		a[i] = i;
		printf("%d  ", a[i]);
	}
	printf("\n");
	change(a);
	for (int i = 0; i < 10; i++) {
		printf("%d  ", a[i]);
	}
	printf("\n %d %d", a, &a);
}
void change(int *a) {
	for (int i = 0; i < 10; i++) {
		a[i] = 10-i;
	}
}