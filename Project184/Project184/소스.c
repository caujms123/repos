#include<stdio.h>
#include<stdlib.h>
void adjust(int a[], int root, int n);
void heapSort(int a[], int n);
void SWAP(int *a,int*b);
void printtree(int a[]);
int main() {
	int a[12];
	for (int i = 1; i < 12; i++) {
		a[i] = rand()%777+1000; // 999보다 큰 4자리 양수  // 100/ 348 /777
	}
	for (int i = 1; i < 12; i++) {
		printf("%d ", a[i]);
	}
	printf("\n----------------------------------------------\n----------------------------------------------\n");
	printtree(a);
	printf("\n");
	heapSort(a,11);
	for (int i = 1; i < 12; i++) {
		printf("%d ",a[i]);
	}
}
void adjust(int a[], int root, int n) {
	int child, rootkey;
	int temp;
	temp = a[root];
	rootkey = a[root];
	child = 2 * root;
	while (child <= n) {
		if ((child < n) && (a[child] < a[child + 1])) //자식이 2개 있음을 보장
			child++;
		if (rootkey > a[child]) //부모가 자식보다 클 때 빠져나온다.
			break;
		else { // 부모가 자식보다 작을 때
			a[child / 2] = a[child]; //부모에다 자식 넣음
			child *= 2; // while문 빠져나가고 a[child / 2] = temp; 할 때 자식에 넣기 위해서 필요함.
		}
	}
	a[child / 2] = temp; 
}
void heapSort(int a[], int n) {
	int i;
	int temp=0;
	printf("<Initial heap> \n");
	for (i = n / 2; i > 0; i--) { // 
		adjust(a, i, n);
		printtree(a);
		printf("----------------------------------------------\n----------------------------------------------\n");
	}
	printf("<heap sort> \n\n");
	for (i = n - 1; i > 0; i--) { // 
		SWAP(&a[1], &a[i + 1]);
		adjust(a, 1, i);
		printtree(a);
		printf("----------------------------------------------\n----------------------------------------------\n");
	}
}
void SWAP(int *a, int*b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void printtree(int a[]) {
	printf("%21d\n",a[1]);
	printf("%13d %16d\n",a[2],a[3]);
	printf("%8d %8d %8d %8d\n",a[4],a[5],a[6],a[7]);
	printf("%d  %d %d  %d\n",a[8],a[9],a[10],a[11]);
	printf("\n");
}