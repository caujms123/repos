#include<stdio.h>
typedef struct {
	int coef;
	int exp;
} polynomial;
polynomial A[3], B[3], C[9];
int len = 0; // C 출력 길이 ex) C(x) = 8x3 +4x2 --> len 은 2
void product_C(void); // 다항식 C를 만들고 출력 
int compare(int a, int b);
int binsearch(int searchnum, int left, int right);
int main() {
	int A_coef[3] = { 2, 2, 3 }; int A_exp[3] = { 3, 2, -4 }; // A(x) = 2x3 + 2x2 + 3x4
	int B_coef[3] = { 7, 3, 4 }; int B_exp[3] = { 0, 1, 2 }; // B(x) = 7 + 3x + 4x2
	for (int i = 0; i < 3; i++) {
		A[i].coef = A_coef[i];
		A[i].exp = A_exp[i];
		B[i].coef = B_coef[i];
		B[i].exp = B_exp[i];
	}
	product_C();
}
void product_C() {
	int left = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			left = binsearch((A[i].exp) + (B[j].exp), 0, len);
			C[left].coef += (A[i].coef)*(B[j].coef);
		}
	}
	printf("C(x) = ");
	int i = 0;
	printf("%dx%d", C[0].coef, C[0].exp);
	for (int i = 1; i < 9; i++) {
		if (C[i].coef == 0) { // 계수가 0인 경우 무시한다.
			continue;
		}
		printf(" + ");
		printf("%dx%d", C[i].coef, C[i].exp);
	}
}
int compare(int a, int b) {
	if (a < b) {
		return -1;
	}
	else if (a == b) {
		return 0;
	}
	else if (a > b) {
		return 1;
	}
};
int binsearch(int AB, int left, int right) {
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		switch (compare(AB, C[mid].exp)) {
		case -1: left = mid + 1;
			break;
		case 0: return mid;
		case 1: right = mid - 1;
		}
	}
	for (int i = 0; i < len - left + 1; i++) {   // C[len] 에서 C[left] 까지 배열을 한 칸씩 뒤로 민다. 총 (len - left + 1) 번 민다.
		C[len + 1 - i].exp = C[len - i].exp;
		C[len + 1 - i].coef = C[len - i].coef;   // 배열을 한 칸씩 뒤로 민다.
	}
	len++;
	C[left].exp = AB; // A*B을 배열에 넣는다.
	C[left].coef = 0; // 밀고 난 후 left에 남아있던 계수를 0으로 초기화한다.
	return left;
}
