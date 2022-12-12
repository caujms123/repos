#include<stdio.h>
#include<stdlib.h>
#define MaxRow 5
int bst[MaxRow][2] = { //binary search tree: �迭�� bst
	{ 3, 17 },
	{ 1, 18 },
	{ 5, 20 },
	{ 4, 20 },
	{ 2, 15 }
};
int mh[MaxRow][2] = { // min heap: �迭�� mh
	{ 2, 20 },
	{ 1, 15 },
	{ 5, 20 },
	{ 1, 19 },
	{ 7, 17 }
};
typedef struct {
	int key;
	int value;
}element;

typedef struct node *treePointer;
typedef struct node{
	element data;
	treePointer leftChild, rightChild;
};

void makebintree(treePointer *tree, int bst[][2], int row);
void insert(treePointer *node, element a);
treePointer modifirdSearch(treePointer root, int key);

void adjust(element[], int root, int n);
void heapSort(element[], int n);

treePointer copy(treePointer original);
void add(treePointer *ptr, element minheap[], int row);
void inorder(treePointer ans);

int main() {
	treePointer tree=NULL;
	treePointer ans=NULL;
	element minheap[MaxRow + 1];
	for (int i = 1; i <= MaxRow; i++) {
		minheap[i].key = mh[i-1][0];
		minheap[i].value = mh[i-1][1];
	}
	makebintree(&tree ,bst,MaxRow); // bst ����
	printf("bst \n");
	inorder(tree);
	heapSort(minheap, MaxRow); // min heap ����
	printf("minheap \n");
	for (int i = 1; i <= MaxRow; i++) {
		printf("(%d, %d)\n", minheap[i].key, minheap[i].value);
	}
	printf("\n");
	printf("���\n");
	ans = copy(tree);
	add(&ans, minheap,MaxRow);
	inorder(ans); // ���� ��� ���
}
void makebintree(treePointer *tree, int bst[][2], int row) {
	element a;
	for (int i = 0; i < row; i++) {
		a.key = bst[i][0];
		a.value = bst[i][1];
		insert(tree, a);
	}
} 
void insert(treePointer *tree, element a) {
	treePointer ptr, temp = modifirdSearch(*tree, a.key);
	if (temp || !(*tree)) {
		ptr = (treePointer)malloc(sizeof(*ptr));
		ptr->data = a;
		ptr->leftChild = ptr->rightChild = NULL;
		if (*tree)
			if (a.key < temp->data.key) temp->leftChild = ptr;
			else if (a.key == temp->data.key) temp->data.value += a.value;
			else temp->rightChild = ptr;
		else *tree = ptr;
	}
}

treePointer modifirdSearch(treePointer tree, int key) { //�����
	while (tree) {
		if (key == tree->data.key) return tree;
		if (key < tree->data.key) {
			if (tree->leftChild == NULL) {
				return tree;
			}
			tree = tree->leftChild;
		}
		else {
			if (tree->rightChild == NULL) {
				return tree;
			}
			tree = tree->rightChild;
		}
	}
	return NULL;
}

void add(treePointer *ans, element minheap[], int row) {
	for (int i = 1; i <= row; i++) {
		insert(ans, minheap[i]);
	}
}
void inorder(treePointer ans) {
	if (ans) {
		inorder(ans->leftChild);
		printf("(%d, %d)\n", ans->data.key, ans->data.value);
		inorder(ans->rightChild);
	}
}; 

void adjust(element a[], int root, int n) {
	int child, rootkey;
	element temp;
	temp = a[root];
	rootkey = a[root].key;
	child = 2 * root;
	while (child <= n) {
		if ((child < n) && (a[child].key > a[child + 1].key)) //�ڽ��� 2�� ������ ���� // ��ħ
			child++;
		if (rootkey < a[child].key) //�θ� �ڽĺ��� Ŭ �� �������´�. // ��ħ
			break;
		else { // �θ� �ڽĺ��� �۰ų� ���� ��
			a[child / 2] = a[child]; //�θ𿡴� �ڽ� ����
			child *= 2; // while�� ���������� a[child / 2] = temp; �� �� �ڽĿ� �ֱ� ���ؼ� �ʿ���.
		}
	}
	a[child / 2] = temp;
}
void heapSort(element a[], int n) {
	int i;
	for (i = n / 2; i > 0; i--) { // 
		adjust(a, i, n);
	}
}
treePointer copy(treePointer original) {
	treePointer temp;
	if (original) {
		temp = (treePointer)malloc(sizeof(*temp));
		temp->leftChild = copy(original->leftChild);
		temp->rightChild = copy(original->rightChild);
		temp->data = original ->data;
		return temp;
	}
	return NULL;
}
/*
for (current = adjlist[v]; current; current = current->link) {
	found[current->node] = False;
	distance[current -> node] = 
}
*/