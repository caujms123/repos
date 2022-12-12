#include <iostream>
using namespace std;
class Stack {
private:
	int *stackPtr, maxLen, topSub;
public:
	Stack() { // a constructor
		stackPtr = new int[100];  // allocate storage
		maxLen = 99;
		topPtr = -1;
	};
	~Stack() { delete[] stackPtr; }; // a destructor
	void push(int number) {
		if (topSub == maxLen)
			cerr << ¡ÈError in push - stack is full\n¡È;
		else stackPtr[++topSub] = number;
	};
	void pop() { ¡¦ };
	int top() { ¡¦ };
	int empty() { ¡¦ };
}
int main() {
	int topOne;
	Stack stk;  //** Create an instance of the Stack class
	stk.push(42);
	stk.push(17);
	topOne = stk.top();
	stk.pop();
	¡¦
}