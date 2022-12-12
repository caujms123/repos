#include "stack.h"
#include<iostream>
using namespace std;
int main() {
	Stack stk;
	for (int i = 0; i < 3; i++) {		int value;		cout << "push: ";		cin >> value;		stk.push(value);	}	for (int i = 0; i < 4; i++) {		stk.pop();	}}