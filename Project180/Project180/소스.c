#include <stdio.h>
#include<stdlib.h>
#define MALLOC(p,s) (p) = malloc(s)
typedef struct listNode *listPointer;
typedef struct listNode {
	int data;
	listPointer link;
};
listPointer invert(listPointer lead) {
	if (!lead) {
		printf("this is empty list\n");
		return NULL;
	}
	listPointer middle, trail;
	middle = NULL;
	while (lead) {
		trail = middle;
		middle = lead;
		lead = lead->link;
		middle->link = trail;

		printNode(lead, lead);
		printNode(middle, middle);
		printNode(trail, trail);
		printf("\n");
	}
	return middle;
}
void printList(listPointer first) {
	printf("The list contains:\n");
	for (; first; first = first->link) {
	printf("%4d\n", first->data);
	}
}
void printNode(listPointer A, char* node) {
	if (A) printf("%s: %p %s->data: %d %s->link: %p \n\n", node, A, node, A->data, node, A->link);
	else printf("%s: NULL\n",node);
}
int main() {
	listPointer L2, second;  // L2 
	MALLOC(L2, sizeof(*L2));
	MALLOC(second, sizeof(*second));
	L2->data = 10;
	L2->link = second;
	second->data = 20;
	second->link = NULL;
	listPointer k = L2;
	printList(L2);
	listPointer A = invert(L2);
	printNode(A, A);


	listPointer L1;		//L1
	MALLOC(L1, sizeof(*L1));
	L1->data = 30;
	L1->link = NULL;
	k = L1;
	printList(L1);
	A = invert(L1);
	printNode(A, A);


	listPointer L0 = NULL;		// L0
	L0->data = 40;
	L0->link = NULL;
	k = L0;
	printList(L0);
	A = invert(L0);
	printNode(A, A);
}