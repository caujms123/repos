#ifndef _소스_H_
#define _소스_H_
#include<vector>
using namespace std;
namespace forNFA {
	typedef struct Delta {
		int state;
		string input;
		int next_state;
	}Delta;
}
namespace forDFA {
	typedef struct Delta {
		vector<int> state;
		string input;
		vector<int> next_state;
	}Delta;
}
class NFA {
	// 입력에 따른 다음 state 정리
	// start
	// final 표시
public:
	vector<int> Q;
	string Sigma;
	vector<forNFA :: Delta> delta;
	int q0;
	int f;
public:
	NFA(void);
	void Print(void);
};
class DFA {
public:
	NFA nfa;
	vector<vector<int>> Q;
	string Sigma;
	vector<forDFA :: Delta> delta;
	vector<int> q0;
	vector<vector<int>> f;
public:
	DFA(NFA);
	vector<int> Closure(int);
	bool vector_find(vector<int>, int);
	void Print(void);
	void PrintVector(vector<int>);
	bool Check(string);
};
#endif
