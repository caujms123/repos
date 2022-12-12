#include<iostream>
#include<string>
#include"소스.h"
using namespace std;

int main() {
	NFA nfa;
	nfa.Print();
	DFA dfa(nfa);
	dfa.Print();
	string a;
	while (1) {
		cout << "입력하세요 : ";
		cin >> a;
		if (dfa.Check(a)) cout << " Accepted "<< endl;
		else  cout << " Rejected " << endl;
	}
}