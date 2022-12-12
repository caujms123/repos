# include<stdio.h>
struct point {
	int x;
	int y;
	double dist;
};
int main() {
	struct point p;
	p.x = 100;
	printf("%d", p.x);
}