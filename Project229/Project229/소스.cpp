#include<stdio.h>
#define N 10
#define C 5
void permu(int a[], int reult[],int depth);
int main() {
	int a[N];
	int result[C];
	for (int i = 0; i < N; i++)
		a[i] = i+1;
	permu(a, result, 0);
}
void permu(int a[],int result[], int depth) {
	if (depth == C) {
		for (int i = 0; i < C; i++) {
			printf("%d ", result[i]);
		}
		printf("\n");
		return;
	}
	int start = 0;
	/*
	if (depth != 0) {//여기부터
		start = result[depth - 1];
	} //여기까지 지우면 순열/ 쓰면 조합
	*/
	for (int j = start; j < N; j++) {
		if (depth == 0) {
			result[depth] = a[j];
			permu(a, result, depth + 1);
		}
		else {
			for (int i = 0; i < depth; i++) {
				if (result[i] == a[j]) {
					goto next;
				}
			}
			result[depth] = a[j];
			permu(a, result, depth + 1);
		}
	next:;
	}
}