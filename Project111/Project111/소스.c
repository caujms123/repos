# include<stdio.h>
# include<string.h>
int main() {
	char a[33]="asdf";
	char r[11];
	strcpy(r, a);
	printf("%s", r);
}