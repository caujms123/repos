#pragma once
#include<vector>
#include<string>
using namespace std;

class Lambda {
private:
	vector <string> variableLam;
	vector <string> variableApp;
	string app;
	string lambda_expression;
public:
	Lambda(void);
	string ToSKI(void);
	void Lam(vector<string>);
	string App(string, string);
	void Transformation();
	void print(void);
};