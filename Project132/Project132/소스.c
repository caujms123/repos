#include<stdio.h>
int main() {
	char str1[7];
	char str2[7];
	fgets(str1, sizeof(str1), stdin);
	fgets(str2, sizeof(str2), stdin);
	printf("\n %s %s", str1, str2);
}