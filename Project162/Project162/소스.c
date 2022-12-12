#include<stdio.h>
#define MAX_DEGREE 101
typedef struct {
	int degree;
	int coef[MAX_DEGREE];
} polynomial;
polynomial mult(polynomial, polynomial);
int main() {
	polynomial a;
	polynomial b;
	a.degree = 4;
	b.degree = 2;
	a.coef[0] = 0;
	a.coef[1] = 0;
	a.coef[2] = 2;
	a.coef[3] = 2;
	a.coef[4] = 3;
	b.coef[0] = 7;
	b.coef[1] = 3;
	b.coef[2] = 4;
	polynomial c = mult(a, b);
	printf("A(X) = "); // A(X) 출력
	for (int i = 0; i <= a.degree; i++) {
		if (a.coef[i] != 0) {
			printf("%dx%d", a.coef[i], i);
			if (i < a.degree)
				printf(" + ");
		}
	}
	printf("\n");
	printf("B(X) = "); // B(X) 출력
	for (int i = 0; i <= b.degree; i++) {
		if (b.coef[i] != 0) {
			printf("%dx%d", b.coef[i], i);
			if (i < b.degree)
				printf(" + ");
		}
	}
	printf("\n");
	printf("C(X) = "); // C(X) 출력
	for (int i = 0; i <= c.degree; i++) {
		if (c.coef[i] != 0) {
			printf("%dx%d", c.coef[i], i);
			if (i < c.degree)
				printf(" + ");
		}
	}
}
polynomial mult(polynomial A, polynomial B) {
	polynomial C;
	int i, j;
	C.degree = A.degree + B.degree;
	for (i = 0; i <= C.degree; i++) {
		C.coef[i] = 0;
	}
	for (i = 0; i <= A.degree; i++) {
		for (j = 0; j <= B.degree; j++) {
			C.coef[i + j] += A.coef[i] * B.coef[j];
		}
	}
	return C;
}