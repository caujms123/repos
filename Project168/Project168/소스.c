#include<stdio.h>
#define MAX_DEGREE 101
#define A_nonzero_terms 3 // A(x) 다항식의 nonzero 항의 수
#define B_nonzero_terms 4 // B(x) 다항식의 nonzero 항의 수
typedef struct {
	int degree;
	float coef[MAX_DEGREE];
} polynomial;
polynomial padd(polynomial, polynomial);
int main() {
	polynomial a;
	polynomial b;
	float A_coef[A_nonzero_terms] = { 2.0, 2.0, 3.0 }; int A_exp[A_nonzero_terms] = { 7, 3, 2 };
	// A(x) = 2x7 + 2x3 + 3x2
	float B_coef[B_nonzero_terms] = { 4.0, 3.0, 7.0, 7.0 }; int B_exp[B_nonzero_terms] = { 5, 3, 1, 0 };
	// B(x) = 4x5 + 3x3 + 7x + 7 
	a.degree = A_exp[0];
	b.degree = B_exp[0];
	int aa=0, bb = 0;

	for (int i = a.degree;i>=0;i--) {
		a.coef[i] = 0;
		if (A_exp[aa] == i) {
			a.coef[a.degree-i] = A_coef[aa];
			printf("%lf %d \n", a.coef[a.degree - i], a.degree - i);
			aa++;
		}
	}
	for (int i = b.degree; i >= 0; i--) {
		b.coef[i] = 0;
		if (B_exp[bb] == i) {
			b.coef[b.degree - i] = B_coef[bb];
			bb++;
		}
	}
	polynomial D = padd(a, b);

	printf("A(X) = "); // A(X) 출력
	printf("%lf\n", a.coef[0]);
	for (int i = 0; i <= a.degree; i++) {
			printf("%lfx%d", a.coef[i], a.degree-i);
		if (i < a.degree && a.coef[i+1] != 0)
			printf(" + ");
	}
	printf("\n");
	printf("B(X) = "); // B(X) 출력
	for (int i = 0; i <= b.degree; i++) {
		if (b.coef[i] != 0) {
			printf("%lfx%d", b.coef[i], b.degree - i);
		}
		if (i < b.degree && b.coef[i + 1] != 0)
			printf(" + ");
	}
	printf("\n");
		printf("D(X) = "); // D(X) 출력
		for (int i = 0; i <= D.degree; i++) {
			if (D.coef[i] != 0) {
				printf("%lfx%d", D.coef[i], D.degree - i);
			}
			if (i < D.degree && D.coef[i + 1] != 0)
				printf(" + ");
		}
}
polynomial padd(polynomial A, polynomial B) {
	polynomial C;
	int i;
	if(A.degree>= B.degree)	C.degree = A.degree;
	else C.degree = B.degree;

	for (i = 0; i <= C.degree; i++) {
		C.coef[i] = 0;
	}
	if (A.degree >= B.degree) {
		for (i = 0; i <= A.degree; i++) {
			C.coef[i] += A.coef[i];
		}
		for (i = 0; i <= B.degree; i++) {
			C.coef[i] += B.coef[A.degree - B.degree + i];
		}
	}
	else {
		for (i = 0; i <= A.degree; i++) {
			C.coef[i] += A.coef[B.degree - A.degree + i];
		}
		for (i = 0; i <= B.degree; i++) {
			C.coef[i] += B.coef[i];
		}
	}
	return C;
}