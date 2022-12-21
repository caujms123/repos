#include<iostream>

int main() {
	int M, N;
	scanf("%d %d", &M, &N);
	int **a = (int **)malloc(sizeof(int*)*N);
	int **record = (int **)malloc(sizeof(int*)*N*M);
	int **record2 = (int **)malloc(sizeof(int*)*N*M);
	int top = -1;
	int bad= 0;
	for (int i = 0; i < N; i++) {
		a[i] = (int*)malloc(sizeof(int)*M);
	}
	for (int i = 0; i < N*M; i++) {
		record[i] = (int*)malloc(sizeof(int) * 2);
		record2[i] = (int*)malloc(sizeof(int) * 2);
	}
	for (int i = 0;i<N;i++) {
		for (int j = 0;j<M;j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j] == 1) {
				top++;
				record[top][0] = i; // 여기서 top은 익은 토마토를 가리키게 됨.
				record[top][1] = j;
			}
			if (a[i][j] == 0) bad++;
		}
	}
	if (bad == 0) {
		printf("0");
		return 0;
	}
	if (bad != 0 && top==-1) {
		printf("-1");
		return 0;
	}
	if(top == -1) {
		printf("0");
		return 0;
	}
	int day = 0;
	int top2= 0; //임시로 0 만듦, 밑에 -1 통과하기 위해
	while (true) {
		if (top2 == -1) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (a[i][j] == 0) {
						printf("-1");
						return 0;
					}
				}
			}
			printf("%d", day-1);
			return 0;
		}
		if (top == -1) {
			for (; top < top2;) {
				top++;
				record[top][0] = record2[top][0];
				record[top][1] = record2[top][1];
			}
		}
		top2 = -1;
		while(top !=-1) {
			int n = record[top][0];
			int m = record[top][1];
			top--;
			if (n - 1 > -1 && a[n - 1][m] == 0) {
				a[n - 1][m] = 1;
				top2++;
				record2[top2][0] = n - 1;
				record2[top2][1] = m;
			}
			if (n + 1 < N && a[n + 1][m] == 0) {
				a[n + 1][m] = 1;
				top2++;
				record2[top2][0] = n + 1;
				record2[top2][1] = m;
			}
			if (m - 1 > -1 && a[n][m - 1] == 0) {
				a[n][m - 1] = 1;
				top2++;
				record2[top2][0] = n;
				record2[top2][1] = m - 1;
			}
			if (m + 1 < M && a[n][m + 1] == 0) {
				a[n][m + 1] = 1;
				top2++;
				record2[top2][0] = n;
				record2[top2][1] = m + 1;
			}
		}
		day++;
		/*for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
		printf("_________________________\n");*/
	}
	return 0;
}