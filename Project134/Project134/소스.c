#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX_SIZE 101
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
void sort(int[], int);
int binsearch(int list[], int searchnum, int left, int right);
int compare(int a, int b);
int main(void) {
	int i, n;
	int list[7] = { 1, 4, 9, 15, 30, 0, 0 };
	/* printf("Enter the number of numbers to generate: ");
	scanf_s("%d", &n);
	if (n<1 || n> MAX_SIZE) {
		fprintf(stderr, "Improper value of n \n");
		exit(0);
	}
	for (i = 0; i < n; i++) {//randomly generate numbers
		list[i] = rand() % 1000;
		printf("%d ", list[i]);
	}
	sort(list, n);
	printf("\n Sorted array:\n");
	for (i = 0; i < n; i++) { // print out sorted numbers 
		printf("%d ", list[i]);
	}
	printf("\n");
	*/
	printf("%d \n", binsearch(list, 30, 0, 4));
	printf("%d \n", binsearch(list, 10, 0, 4));
	printf("%d \n", binsearch(list, 10, 0, 5));
	printf("%d \n", binsearch(list, 30, 0, 5));
	return 0;
}
void sort(int list[], int n) {
	int i, j, max, temp;
	for (i = 0; i < n - 1; i++) {
		max = i;
		for (j = i + 1; j < n; j++) {
			if (list[j] > list[max]) {
				max = j;
			}
		}
		SWAP(list[i], list[max], temp);
	}
}
int binsearch(int list[], int searchnum, int left, int right) {
	int mid;
	int r = right;
	while (left <= right) {
		mid = (left + right) / 2;
		switch (compare(list[mid], searchnum)) {
		case -1: left = mid + 1;
			break;
		case 0: return mid;
		case 1: right = mid - 1;
		}
	}
	int k = 0;
	for (int i = 0; i < r - left + 1; i++) {   //  r은 인자로 받은 right 이다. list[r] 에서 부터 한 칸씩 뒤로 (r - left + 1) 번 민다.
		list[r + 1 - k] = list[r - k];    // 배열을 한 칸씩 뒤로 민다.
		k++;
	}
	list[left] = searchnum; // searchnum을 배열에 넣는다.
	return -1;
}
int compare(int a, int b) {
	if (a < b) {
		return -1;
	}
	else if (a == b) {
		return 0;
	}
	else if (a > b) {
		return 1;
	}
};
