#include <stdio.h>
#include <math.h>
void print1(int *ptr, int row);
int main(void) {
	int one[] = { 0,1,2,3,4 };
	print1(one, 5);
}
void print1(int ptr[], int rows)
{/*print out a one-dimensional array using a pointer */
	int i;
	printf("Address Contents\n");
	for (i = 0; i < rows; i++)
		printf("%8u%5d\n", &ptr[i], ptr[i]);
	printf("\n");
}