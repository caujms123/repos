#include <iostream>
#include "stack.h"
using namespace std;
Node::~Node() { delete next; }
int Node::getValue() { return value; }
Node* Node::getnext() { return next; }
void Node::setValue(int value) { this->value = value; }
void Node::setNext(Node *next) { this->next = next; }

Stack::Stack() { //** A constructor
	first = new Node(0,NULL);
	cur = first;
	topSub = -1;
}
Stack::~Stack() {
	Node* temp = first;
	while (temp->getnext() != NULL) {
		temp = temp->getnext();
		delete first;
		first = temp;
	}
	delete temp;
} //** A destructor
void Stack::push(int number) {
	cur -> setNext(new Node(number, NULL));
	cur = cur->getnext();
	topSub++;
}
void Stack::pop() {
	if (topSub == -1)
		cout << "Error in pop--stack is empty\n";
	else {
		cout << "pop: " << cur->getValue() << endl;
		Node* temp = first;
		while ((temp->getnext()) != cur) {
			temp = temp->getnext();
		}
		delete cur;
		cur = temp;
		cur->setNext(NULL);
		topSub--;
	}
}
int Stack::top() {
	if (topSub == -1)
		cout << "Error in top--stack is empty\n";
	else
		return (cur ->getValue());
}
int Stack::empty() { return (topSub == -1); }