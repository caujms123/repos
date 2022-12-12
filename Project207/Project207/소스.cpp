#include<iostream>
#include<string>
#include<vector>
using namespace std;
typedef struct ingredient {
	string name;
	string amount;
}ingredient;
vector<ingredient> GetIngredients(void);
int main() {
	vector<ingredient> c = GetIngredients();
	for (int i=0;i<2;i++)
		cout << c[i].name << c[i].amount << endl;
}
vector<ingredient> GetIngredients(void) {
	vector<ingredient> B;
	ingredient c;
	c.name = "CCCC";
	c.amount = "AAAA";
	B.push_back(c);
	B.push_back(c);
	return B;
}