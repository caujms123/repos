#include<iostream>

int N;
int chess(int queen[], int depth);
int main() {
	scanf("%d", &N); // 1<=N<=14
	int queen[14];
	for (int i = 0; i < 14; i++)
		queen[i] = -1;
	int result = chess(queen, 0);
	printf("%d", result);
}
int chess(int queen[], int depth) {
	int result = 0;
	if (depth == N - 1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < depth; j++) { // l 제거
				if (i == queen[j]) goto out2;
				if (depth - j == i - queen[j]) goto out2;
				if (depth - j == queen[j] - i) goto out2;
			}
			result++;
		out2:;
		}
		return result;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < depth; j++) { // l 제거
			if (i == queen[j]) goto out;
			if (depth - j == i - queen[j]) goto out;
			if (depth - j == queen[j] - i) goto out;
		}
		queen[depth] = i;
		result += chess(queen, depth + 1);
		queen[depth] = -1;
	out:;
	}
	return result;
}