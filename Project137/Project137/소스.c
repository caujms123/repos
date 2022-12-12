#include<stdio.h>
typedef struct {
	int x;
	int y;
}poly;
int main() {
	poly A;
	A.x = 0;
	printf("%d %d %d %d", &A , &(A.x),&A+0.5, &(A.y));
}