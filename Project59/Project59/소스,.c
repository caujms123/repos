#include<stdio.h>
int f(int k) {
	int sum = 1;
	sum *= k;
	if (k == 1)
		return sum;
	return f(k - 1);
}
int main() {
	int num = 10;
	int sum = f(num);
	printf("%d", sum);
}