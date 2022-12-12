#include<iostream>
#include<string>
#include<vector>
using namespace std;
typedef struct ingredient{
	string name;
	string amount;
}ingredient;
vector<ingredient> GetIngredients(void);
int main() {
	vector<ingredient> c = GetIngredients();
	cout << c[0].name  << c[0].amount <<endl;
}
vector<ingredient> GetIngredients(void) {
	vector<ingredient> B;
	ingredient c;
	c.name = "CCCC";
	c.amount = "AAAA";
	B.push_back(c);
	return B;
}