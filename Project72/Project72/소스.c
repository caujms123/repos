#include<stdio.h>
struct point {
	int x;
	int y;
	double dist;
}p;


int main() {
	struct point p = {10,20,30.0};
	struct point *ptr = &p;
	ptr->x = 99;
	printf("%d", p.x);
}