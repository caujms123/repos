#include<iostream>
#include<string>
#include"lambda.h"

int main() {
	Lambda expr;
	vector <string> lam = {"m", "n", "f", "x"};

	expr.Lam(lam);
	expr.App(expr.App("m", "f"), expr.App(expr.App("n", "f"), "x"));

	// succ 1을 표현하면 App(Lam([“n”, “f”, “x”], App(“f”, App(App(“n”, “f”), “x”))), Lam([“f”, “x”], App(“f”, “x”)))이 된다.
	expr.print();
	//string SKI = expr.ToSKI();
	//cout << SKI ;
	
}