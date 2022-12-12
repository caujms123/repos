#include<stdio.h>
int add(x);
int main(void) {

}
int a(int n) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return add(n - 1) + add(n - 2);
}
// char %c %s int %d double %lf long %ld ongdouble %lf float %f longlong %lld