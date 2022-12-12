#include<iostream>
#include<string>
#include"lambda.h"
using namespace std;
/*
T[x] => x
T[(E�� E��)] => (T[E��] T[E��])
T[��x.E] => (K T[E]) (if x does not occur free in E)
T[��x.x] => I
T[��x.��y.E] => T[��x.T[��y.E]] (if x occurs free in E)
T[��x.(E�� E��)] => (S T[��x.E��] T[��x.E��]) (if x occurs free in E�� or E��)
6���� ��Ģ�� ���ؼ� ����
Lam Add ����
T�� ������ SKI ���ϱ�

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