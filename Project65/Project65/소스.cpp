#include<iostream>
class a {
private:
	int aa;
public:
	a() {
		printf("a");
	}
};
class b : public a {
public:
	b() {
		printf("b");
	}
};
int main() {
	b bnw;
}