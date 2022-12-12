#include <stdio.h>
#include <math.h>
#define MAX_SIZE 101
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
void rsort(int[], int, int); //selection sort;
int rfind_min(int list[], int i, int n, int);
int main(void) {
	int i, n;
	int list[MAX_SIZE];
	printf("Enter the number of numbers to generate: ");
	scanf_s("%d", &n);
	if (n<1 || n> MAX_SIZE) {
		fprintf(stderr, "Improper value of n \n");
		exit();
	}
	for (i = 0; i < n; i++) {/*randomly generate numbers*/
		list[i] = rand() % 1000;
		printf("%d ", list[i]);
	}
	rsort(list, n, 0);
	printf("\n Sorted array:\n");
	for (i = 0; i < n; i++) { /* print out sorted numbers */
		printf("%d ", list[i]);
	}
	printf("\n");
}
void rsort(int list[], int n, int i) {
	int min, temp;
	if (i == n - 1) {
		return;
	}
	else {
		min = rfind_min(list, i, n, i);
		SWAP(list[i], list[min], temp);
		rsort(list, n, i + 1);
	}
}
int rfind_min(int list[], int i, int n, int min) {
	if (i < n) {
		if (list[i] < list[min])
			min = i;
		return rfind_min(list, i + 1, n, min);
	}
	return min;
}
