#include<iostream>
#include<string>
#include"�ҽ�.h"
using namespace std;

int main() {
	NFA nfa;
	nfa.Print();
	DFA dfa(nfa);
	dfa.Print();
	string a;
	while (1) {
		cout << "�Է��ϼ��� : ";
		cin >> a;
		if (dfa.Check(a)) cout << " Accepted "<< endl;
		else  cout << " Rejected " << endl;
	}
}