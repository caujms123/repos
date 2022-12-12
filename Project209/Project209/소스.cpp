#include<iostream>
#include<string>
#include "소스.h"
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
NFA :: NFA(void) {
	/*
	// (a+b)*
	Q = {0,1,2,3,4,5,6,7};
	Sigma = "ab";
	delta.push_back({ 0, "a", 1 });
	delta.push_back({ 2, "b", 3 });
	delta.push_back({ 4, "eps", 0 });
	delta.push_back({ 4, "eps", 2 });
	delta.push_back({ 1, "eps", 5 });
	delta.push_back({ 3, "eps", 5 });
	delta.push_back({ 6, "eps", 4 });
	delta.push_back({ 6, "eps", 7 });
	delta.push_back({ 5, "eps", 4 });
	delta.push_back({ 5, "eps", 7 });
	q0 = 6;
	f = 7;
	*/
	Q = { 0,1,2,3,4,5,6,7,9,11,13 };
	Sigma = "ab";
	delta.push_back({ 0, "a", 1 });
	delta.push_back({ 2, "b", 3 });
	delta.push_back({ 4, "eps", 0 });
	delta.push_back({ 4, "eps", 2 });
	delta.push_back({ 1, "eps", 5 });
	delta.push_back({ 3, "eps", 5 });
	delta.push_back({ 6, "eps", 4 });
	delta.push_back({ 6, "eps", 7 });
	delta.push_back({ 5, "eps", 4 });
	delta.push_back({ 5, "eps", 7 });
	delta.push_back({ 7, "a", 9 });
	delta.push_back({ 9, "b", 11 });
	delta.push_back({ 11, "b", 13 });

	/*delta.push_back({ 7, "a", 8 });
	delta.push_back({ 8, "eps", 9 });
	delta.push_back({ 9, "b", 10 });
	delta.push_back({ 10, "eps", 11 });
	delta.push_back({ 11, "b", 12 });
	delta.push_back({ 12, "eps", 13 });*/
	q0 = 6;
	f = 13;
}
void NFA :: Print(void){
	cout << "esp-NFA " << endl;
	cout << "Q: {";
	for (int i = 0; i < Q.size()-1; i++) {
		cout << "q" << Q[i] << ", ";
	}
	cout << "q" << Q[Q.size() - 1] << "}" << endl;
	// 시그마 출력*********************************
	cout << "Sigma: {";
	for (int i = 0; i < Sigma.size()-1 ; i++) {
		cout << Sigma[i] << ", ";
	}
	cout << Sigma[Sigma.size()-1] << "}" << endl;
	// **********************************
	cout << "Delta: as shown below" << endl;
	// 시작 출력 **********************
	cout << "q0: " << q0 << endl;
	// 끝 출력 *****************
	cout << "F: " << "{q" << f << "}" << endl;
	// 델타 출력 ********
	cout << "where Delta is " << endl;
	for (int i = 0; i < delta.size(); i++) {
		cout << "Delta(" <<"q"<< delta[i].state << ", "<< delta[i].input <<") = "<< "q" << delta[i].next_state << endl;
	}
}

DFA::DFA(NFA Nfa) {
	nfa = Nfa;
	q0 = Closure(nfa.q0);
	sort(q0.begin(), q0.end());
	Q.push_back(q0);
	Sigma = nfa.Sigma;;
	// qo, Sigma 완성.
	//PrintVector(q0);
	int i = 0;
	while (1) {
		for (int q = 0; q < Sigma.size(); q++) { // 입력 확인
			string str;
			str += Sigma[q];
			vector<int> for_insert;
			for (int j = 0; j < Q[i].size(); j++) { // Q의 마지막 원소(벡터)의 개수
				for (int k = 0; k < nfa.delta.size(); k++) { // 확인해야할 delta의 개수
					vector<int> b;
					if (nfa.delta[k].state == Q[i][j] && nfa.delta[k].input == str) {
						b = Closure(nfa.delta[k].next_state);
						for_insert.insert(for_insert.end(), b.begin(), b.end());
					}
				}
			}
			// 여기서 삽입
			if (for_insert.empty()) continue; // 이런 경우가 존재?
			sort(for_insert.begin(), for_insert.end());
			for_insert.erase(unique(for_insert.begin(), for_insert.end()), for_insert.end());
			delta.push_back({ Q[i],str,for_insert });
			for (int u = 0; u < Q.size(); u++) {
				if (Q[u] == for_insert) {
					goto out;
				}
			}
			Q.push_back(for_insert);
		out:;
		}
		//cout << Q.size()-1 << i;
		if (Q.size()-2 >= i) {
			i++;
			//cout << Q.size() << i;
		}
		else {
			//cout << "zzzzzzzzz";
			break;
		}
	}
	// Q, delta 완성
	for (int i = 0; i < Q.size(); i++) {
		if (vector_find(Q[i],nfa.f)) {
			f.push_back(Q[i]);
		}
	}
	//f완성
}
bool DFA::vector_find(vector<int> a, int b) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == b) {
			return true;
		}
	}
	return false;
}
vector<int> DFA :: Closure(int q0) {
	vector<int> answer, stack;
	stack.push_back(q0);
	while (!stack.empty()) {
		int check = stack.back(); stack.pop_back();
		answer.push_back(check);
		for (int i = 0; i < nfa.delta.size(); i++) {
			if (nfa.delta[i].state == check && nfa.delta[i].input == "eps") {
				stack.push_back(nfa.delta[i].next_state);
			}
		}
	}
	return answer;
}
void DFA :: Print(void) {
	cout << "DFA for NFA" << endl;
	cout << "Q: {";
	for (int i = 0;i<Q.size()-1;i++) {
		PrintVector(Q[i]);
		cout << ", ";
	}
	PrintVector(Q[Q.size() - 1]);
	cout <<"}" << endl;
	// 시그마 출력*********************************
	cout << "Sigma: {";
	for (int i = 0; i < Sigma.size() - 1; i++) {
		cout << Sigma[i] << ", ";
	}
	cout << Sigma[Sigma.size() - 1] << "}" << endl;
	// **********************************
	cout << "Delta: as shown below" << endl;
	// 시작 출력 **********************
	cout << "q0: {";
	PrintVector(q0);
	cout << "}" << endl;
	// 끝 출력 *****************
	cout << "F: {";
	for (int i = 0; i < f.size()-1; i++) {
		PrintVector(f[i]);
		cout << ", ";
	}
	PrintVector(f[f.size()-1]);
	cout << "}" << endl;
	// 델타 출력 ********
	cout << "where Delta is " << endl;
	for (int i = 0; i < delta.size(); i++) {
		cout << "Delta(";
		PrintVector(delta[i].state);
		cout <<", " <<delta[i].input << ") = ";
		PrintVector(delta[i].next_state);
		cout << endl ;
	}
}
void DFA :: PrintVector(vector<int> Q) {
	cout << "{";
	for (int j = 0; j < Q.size() - 1; j++) {
		cout << "q" << Q[j] << ", ";
	}
	cout << "q" << Q[Q.size() - 1] << "}";
	return;
}
bool DFA::Check(string a){
	vector<int> final_state = delta[0].state;
	bool check = false;
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < delta.size(); j++) {
			string str;
			str += a[i];
			if (delta[j].input == str && final_state == delta[j].state) {
				final_state = delta[j].next_state;
				check = true;
				break;
			}
		}
		if (check == false) return false;
		check = false;
	}
	//PrintVector(final_state);
	for (int i = 0; i < f.size(); i++) {
		if (f[i] == final_state) {
			return true;
		}
	}
	return false;
}