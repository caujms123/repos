#include<iostream>
#include<string>
#include"lambda.h"

int main() {
	Lambda expr;
	vector <string> lam = {"m", "n", "f", "x"};

	expr.Lam(lam);
	expr.App(expr.App("m", "f"), expr.App(expr.App("n", "f"), "x"));

	// succ 1�� ǥ���ϸ� App(Lam([��n��, ��f��, ��x��], App(��f��, App(App(��n��, ��f��), ��x��))), Lam([��f��, ��x��], App(��f��, ��x��)))�� �ȴ�.
	expr.print();
	//string SKI = expr.ToSKI();
	//cout << SKI ;
	
}