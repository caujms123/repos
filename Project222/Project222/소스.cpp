#include <iostream>
#include "¼Ò½º.h"
using namespace std;


template <typename T>
Stack<T>::Stack(int size) {
	top = -1;
	this->size = size;
	stackPtr = new T[size];
}
template <typename T>
Stack<T>::~Stack()
{
	if (isEmpty()) return;
	delete[] stackPtr;

}

template <typename T>
bool Stack<T>::push(const T& value)
{
	if(isFull()) return false;
	stackPtr[++top] = value;
	return true;

}

template <typename T>
bool Stack<T>::pop(T& value)
{
	if (isEmpty()) return false;
	value = stackPtr[top--];
	return true;
}

template <typename T>
bool Stack<T>::isEmpty() const
{
	if (top == -1) return true;
	return false;
}

template <typename T>
bool Stack<T>::isFull() const
{
	if (top == size-1) return true;
	return false;
}
