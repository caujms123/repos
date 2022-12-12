#include<stdio.h>
int main() {
	int *arr[3] = { {1,2,3},{4,5,6} };
	arr = 
	int sum = 0; 
	int *ptr = arr;
	for (int i = 0; i < 6; i++) {
		sum += *(ptr++);
	}
	printf("sum = %d\n", sum);
}