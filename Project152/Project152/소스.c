#include<stdio.h>
#include<stdlib.h>
int main() {
	char n[2000];
	char a[2000];
	char b[2000] = {0};
	scanf("%s", n);
	int k = strlen(n);
	//printf("%d", k); 10110111
	for (int i = 0;i<k;i++) {
		a[k-1 - i] = n[i];
	}
	for (int i = 0; i < k; i++) {
		b[k +3 - i] = n[i];
	}
	int kk = 0;
	for (int i = 0; i < k + 4; i++) {
		if ((b[i] == '1' && a[i] == '1')&&kk==0) {
			n[i] = '0';
			kk = 1;
		}
		else if ((b[i] == '1' && a[i] == '1') && kk == 1) {
			n[i] = '1';
			kk = 1;
		}
		else if ((b[i] == '1' || a[i] == '1')&&kk==0) {
			n[i] = '1';
			kk = 0;
		}
		else if ((b[i] == '1' || a[i] == '1') && kk == 1) {
			n[i] = '0';
			kk = 1;
		}
		else if(kk==1){
			n[i] = '1';
			kk = 0;
		}
		else if (kk == 0) {
			n[i] = '0';
			kk = 0;
		}
	}
	if (kk==1){
		printf("1");
	}
	for (int i = k+3; i >= 0; i--) {
		printf("%c", n[i]);
	}
}