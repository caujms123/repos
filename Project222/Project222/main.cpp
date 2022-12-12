/*#include <iostream>
using namespace std;
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
template <typename T>
Stack<T>::Stack(int size) {
	top = -1;
	this->size = size;
	stackPtr = new T[size];
}
template <typename T>
Stack<T>::~Stack()
{
	delete[] stackPtr;

}

template <typename T>
bool Stack<T>::push(const T& value)
{
	if (isFull()) return false;
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
	if (top == size - 1) return true;
	return false;
}

int main()
{
	int x, y;
	Stack<int> intStack(5);
	intStack.push(5);
	intStack.push(8);
	intStack.pop(x);
	intStack.pop(y);

	cout << x << endl;
	cout << y << endl;

}*/

#include <iostream>
#include <vector>
#include <algorithm>  // std::transform()

using namespace std;

// vector1의 모든 요소에 순차적으로 2를 곱하여 다시 넣습니다.

int main(void)
{

	vector<int> vector1{ 1, 2, 3, 4, 5 };

	std::transform(vector1.begin(), vector1.end(), vector1.begin(),
		[](int n) { return n * 2; });

	// 2 4 6 8 10
	for (int i = 0; i < vector1.size(); i++) {
		cout << vector1[i] << " ";
	}
	return 0;
}