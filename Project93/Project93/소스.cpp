#include<iostream>
#include<algorithm>
#include<list>
#include<vector>
using namespace std;
int main() {
	int a, b;
	int sum = 0;
	scanf("%d %d", &a, &b);
	vector<int> is;
	int kk;
	for (int i = 1; i <=a; i++) {
			is.push_back(i);
	}
	vector<int>::iterator iter = is.begin();
	int kkk=0;
	printf("<");
	for (int i = 1; i <= a; i++) {
		for (int j = 0; j < b-1; j++) {
			if (iter == is.end()) {
				iter = is.begin();
				kkk = 0;
			}
			iter++;
			kkk++;
			if (iter == is.end()) {
				iter = is.begin();
				kkk = 0;
			}
		}
		printf("%d", *iter);
		if(i!=a)
			printf(", ");
		is.erase(iter);
		iter = is.begin()+kkk;
	}
	printf(">");
}
