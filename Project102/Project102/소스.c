#include <stdio.h>
int main(){
	int o;
	int b;
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &o, &b);
		int a = o % 10;
		if (a == 1 || a == 5 || a == 6) {
			printf("%d\n",a);
		}
		else if (a == 2 || a == 3 || a == 7 || a == 8) {
			if (b % 4 == 0) {
				printf("%d\n",a*a*a*a%10);
			}
			else if (b % 4 == 3) {
				printf("%d\n",a*a*a%10);
			}
			else if (b % 4 == 2) {
				printf("%d\n",a*a%10);
			}
			else if(b%4==1) {
				printf("%d\n",a);
			}
		}
		else if (a == 4 || a == 9 ) {
			if (b % 2 == 0) {
				printf("%d\n", a*a % 10);
			}
			else {
				printf("%d\n", a);
			}
		}
		else if (a == 0) {
			printf("10\n");
		}
	}
}