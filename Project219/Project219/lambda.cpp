#include<iostream>
#include<string>
#include"lambda.h"
using namespace std;
/*
T[x] => x
T[(E₁ E₂)] => (T[E₁] T[E₂])
T[λx.E] => (K T[E]) (if x does not occur free in E)
T[λx.x] => I
T[λx.λy.E] => T[λx.T[λy.E]] (if x occurs free in E)
T[λx.(E₁ E₂)] => (S T[λx.E₁] T[λx.E₂]) (if x occurs free in E₁ or E₂)
6가지 규칙에 대해서 구현
Lam Add 구현
T를 적용해 SKI 구하기

succ = \n f x -> f(n f x)

add = \m n f x -> m f (n f x)

0 = \f x -> x

1 = \f x -> f x
*/
Lambda :: Lambda(void) {}

string Lambda::App(string a, string b) {
	string app;
	if (b.length() == 0) {
		 app = " ( "+ a + " ) ";
	}
	app = " ( " + a + " " + b + " ) ";
	lambda_expression += app;
	string ab;
	return ab;
}

void Lambda::Lam(vector<string> variable) {
	variableLam = variable;
	for (int i =0;i<variable.size();i++)
		lambda_expression += variable[i]+".";
}
void Lambda::Transformation() {}
string Lambda :: ToSKI() {
		string ski;
		return ski;
}
void Lambda::print(void) {
	cout << lambda_expression << endl;
}