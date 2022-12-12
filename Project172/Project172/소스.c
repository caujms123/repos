#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define Row 4
#define Col 4
#define A_nonzero_elements 3 // A matrix�� nonzero element�� ��
int AP[(Row * Col) / 8] = { 129, 8 }; int AV[A_nonzero_elements] = { 11, 7, -1 };
#define B_nonzero_elements 4 // B matrix�� nonzero element�� ��
int BP[(Row * Col) / 8] = { 65, 136 }; int BV[B_nonzero_elements] = { 5, 2, 4, 1 };
int main() {
	int t = 0; // D ��Ʈ���� ���� ����
	int DP[(Row*Col) / 8] = { 0, }; // 10���� ����
	int DPP[(Row*Col) / 8] = { 0, }; // DP ����

	for (int i = 0; i < (Row*Col) / 8; i++) { //DP ���ϱ�
		DP[i] = AP[i] | BP[i];
		DPP[i] = DP[i];
	}
	for (int i = 0; i < (Row*Col) / 8; i++) { // t ���ϱ�
		for (int j = 0; j < 8; j++) {
			t += (DPP[i] & 1);
			DPP[i] >>= 1;
		}
	}
	int *DV = (int*)malloc(t * sizeof(int));
	int a, b;
	int count = t-1 ;
	int av = A_nonzero_elements - 1, bv = B_nonzero_elements - 1;

	for (int i = (Row*Col) / 8 - 1; i >= 0; i--) { // DV ���ϱ�
		for (int j = 0; j < 8; j++) {
			a = AP[i] & 1;
			b = BP[i] & 1;
			AP[i] >>= 1;
			BP[i] >>= 1;
			if (a == 1 && b == 1) {
				DV[count] = AV[av] + BV[bv];
				printf("%d\n", DV[count]);
				if (AV[av] + BV[bv] == 0) { // ������ �� 0�̵Ǹ� ����
					//printf("..%d",j);
					t--;
					DP[i] -= pow(2, j);
				}
				av--; bv--; count--;
			}
			else if (a == 1 && b == 0) {
				DV[count] = AV[av];
				av--; count--;
			}
			else if (a == 0 && b == 1) {
				DV[count] = BV[bv];
				bv--; count--;
			}
		}
	}
	printf("row: %d\ncol: %d\nt : %d\n", Row, Col, t);
	printf("DP[] : %d", DP[0]);
	for (int i = 1; i < (Row*Col) / 8; i++) {
		printf(", %d", DP[i]);
	}
	printf("\n");
	printf("DV[] : %d", DV[0]);
	for (int i = 1; i <= t; i++) {
		printf(", %d", DV[i]);
	}
}