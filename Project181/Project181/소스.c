#include <stdio.h>
#include<stdlib.h>
#define MALLOC(p,s) (p) = malloc(s)
typedef struct listNode *listPointer;
typedef struct listNode {
	int data;
	listPointer link;
};
listPointer cinvert(listPointer lead);
void printList(listPointer first);
void printNode(listPointer A, char* node);
void ccreat(listPointer *A, int data);
void insert(listPointer *first, listPointer x, int data);
int main() {
	listPointer L2;
	ccreat(&L2, 10); // 원형리스트 L2 생성
	insert(&L2, L2, 20); // 두 번째 노드 삽입
	printList(L2); // 생성한 리스트 출력
	listPointer A = cinvert(L2); // invert
	printNode(A, "middle"); // 반환받은 노드 출력
	printf("\n");

	listPointer L1;
	ccreat(&L1, 10); //L1 
	printList(L1);
	A = cinvert(L1);
	printNode(A, "middle");
	printf("\n");

	listPointer L0 = NULL;		// L0
	printList(L0);
	A = cinvert(L0);
	printNode(A, "middle");
}
listPointer cinvert(listPointer lead) {
	if (!lead) {
		printf("empty list\n");
		return NULL;
	}
	listPointer middle, trail, temp;
	temp = lead;
	middle = lead;
	while (1) {
		if (middle->link == lead) {
			break;
		}
		middle = middle->link;
	}
	do {
		trail = middle;
		middle = lead;
		lead = lead->link;
		middle->link = trail;

		printNode(lead, "lead");
		printNode(middle, "middle");
		printNode(trail, "trail");
		printf("\n");
	} while (lead != temp);
	return middle;
}
void printList(listPointer first) {
	listPointer temp = first;
	if (first) {
		printf("The list contains:\n");
		do {
			printf("%p %d %p\n", first, first->data, first->link);
			first = first->link;
		} while (first != temp);
	}
	else {
		printf("empty list\n");
	}
}
void printNode(listPointer A, char* node) {
	if (A) printf("%s: %p %s->data: %d %s->link: %p \n", node, A, node, A->data, node, A->link);
	else printf("%s: NULL\n", node);
}
void ccreat(listPointer *A, int data) {
	listPointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->data = data;
	temp->link = temp;
	*A = temp;
}
void insert(listPointer *first, listPointer x, int data) {
	// node x 뒤에 node를 넣기
	listPointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->data = data;
	if (*first) {
		temp->link = x->link;
		x->link = temp;
	}
	else {
		temp->link = temp;
		*first = temp;
	}
}