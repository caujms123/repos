#include<iostream>
using namespace std;
void SWAP(int* a, int b= 10) {
	int temp= *a;
	*a = b;
	b = temp;
}
void SWAP(int* a) {
	;
}
int main(void) {
	int a = 10, b = 20;
	SWAP(&a);
	cout << a <<' '<< b;
	
}