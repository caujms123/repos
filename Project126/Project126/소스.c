#include<stdio.h>


int main()
{
	// unsignd 32bit int -> 111...1 => 
	char a = 200, b = 100, c = -100;
	char n1 = a + b;
	char n2 = c - b;
	char n3 = b - c;
	printf("%d %d %u", n1, n2, n3);
}
