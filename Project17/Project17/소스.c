#include <stdio.h>
int main(void) {
	int i = 0;
	int j = 0;
	while (j<10) {
		while (i<j) {
			printf("O");
			i++;
		}
		printf("* \n");
		j++;
		i = 0;
	}
}