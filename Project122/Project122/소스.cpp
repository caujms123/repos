#include<stdio.h>
int abs(int a, int b) {
	if (a>=b) {
		return a - b;
	}
	return b - a;
}
int main() {
	int a[6];
	int b=0, c;
	for (int i = 0; i < 6; i++) {
		scanf("%d", &a[i]);
	}
	while(1){
		if (a[0] > a[4] && a[1] > a[5]) {
			b++;
			a[0]--;
			a[1]--;
		}
		else if (a[0] < a[4] && a[1] < a[5]) {
			b++;
			a[0]++;
			a[1]++;
		}
		else {
			break;
		}
	}
	b += abs(a[0], a[4]) + abs(a[1], a[5]);
	c = abs(a[2],a[4]) + abs(a[3],a[5]);
	if (b < c) {
		printf("bessie");
	}
	else if (b==c) {
		printf("tie");
	}
	else {
		printf("daisy");
	}
}