#pragma once
#include <iostream>
class Node
{
private:
	int     value;      // 밸류 저장용
	Node   *next;      // Node를 가르킬 수 있는 포인터(화살표)
public:
	Node() {};
	Node(int v, Node *n) : value(v), next(n) {}
	~Node();
	int getValue();
	Node* getnext();
	void setValue(int value);
	void setNext(Node *next);
};
class Stack {
private: //** These members are visible only to other
 //** members and friends (see Section 11.6.3)
	Node *first;
	Node *cur;
	int topSub;
public: //** These members are visible to clients 
	Stack(); //** A constructor
	~Stack(); //** A destructor
	void push(int);
	void pop();
	int top();
	int empty();
};