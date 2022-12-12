#include <stdio.h>
int asdf(int *b) {

}
int main() {
	int(*a)[100];
	int b[100][100] = { {1}, };
	a = b;
	printf("%d %d",b[2],a[2]);
}