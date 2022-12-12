#pragma once
template<typename T>
class Stack {
public:
	Stack(int = 100);
	~Stack();
	bool push(const T&);
	bool pop(T&);
	bool isEmpty() const;
	bool isFull() const;
private:
	int size;
	int top;
	T *stackPtr;
};