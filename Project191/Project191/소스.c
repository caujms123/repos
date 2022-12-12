#include<stdio.h>
#include<math.h> 
int data[100000000] = { 0 };
void aaa(int power) {
	int i, j, k, num;
	int next_sum = 0, temp_number, index = 0;
	num = 2;
	data[0] = num;
	for (i = 1; i < power; i++) {
		temp_number = 0; next_sum = 0;
		for (j = index; j >= 0; j--) {
			temp_number = data[j] * num + next_sum; next_sum = 0;
			if (temp_number > 9) {
				data[j] = temp_number % 10;
				if (j == 0) {
					for (k = index; k >= 0; k--) {
						data[k + 1] = data[k];
					} data[0] = temp_number / 10;
					index++;
				}
				else {
					next_sum = temp_number / 10;
				}
			}
			else { data[j] = temp_number; }
		}
	}
	if (index == 0) {
		printf("%d\n", data[index] - 1);
		return;
	}
	if (data[index] > 0) {
		data[index] -= 1;
	}
	else if (data[index] == 0) {
		data[index - 1] -= 1;
	}
	for (i = 0; i <= index; i++)
		printf("%d", data[i]);
	printf("\n");
}
char a[4000000];

int main() {
	int kkk;
	int n;
	scanf("%d", &n);
	aaa(n);
	if (n > 20) {
		return 0;
	}
	a[0] = '1';
	a[1] = '2';
	a[2] = '1';
	a[3] = '3';
	a[4] = '2';
	a[5] = '3';
	if (n == 1) {
		printf("1 3");
		return 0;
	}
	if (n == 2) {
		for (int i = 0; i < (int)pow(2, n) - 1; i++) {
			printf("%c %c\n", a[2 * i], a[2 * i + 1]);
		}
		return 0;
	}

	for (int i = 3; i <= n; i++) {
		kkk = (int)pow(2, i);
		int k = 0;
		int jjj = (kkk - 1) * 2;
		for (int j = kkk; j < jjj; j++) {
			a[j] = a[k++];
		}
		for (int j = 0; j < kkk - 2; j++) {
			if (a[j] == '2')
				a[j] = '3';
			else if (a[j] == '3')
				a[j] = '2';
		}
		a[kkk - 2] = '1';
		a[kkk - 1] = '3';
		for (int j = kkk; j < jjj; j++) {
			if (a[j] == '1')
				a[j] = '2';
			else if (a[j] == '2')
				a[j] = '1';
		}
	}
	for (int i = 0; i < kkk - 1; i++) {
		printf("%c %c\n", a[2 * i], a[2 * i + 1]);
	}
	return 0;
}