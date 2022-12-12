#include<iostream>
#include<windows.h>
#include<fstream>
#include"Student.h"
using namespace std;
int main() {
	StudentDB studentDB("file1.txt", "file2.txt");
	int choice;
	while (1) {
		system("cls");
		ShowMenu();
		cout << "선택: ";
		cin >> choice;
		while (getchar() != '\n');
		cin.clear();
		cout << endl;
		switch (choice) {
		case INSERT:
			system("cls");
			studentDB.Insert();
			break;
		case SEARCH:
			system("cls");
			studentDB.Search();
			break;
		case SORT:
			system("cls");
			studentDB.Sort();
			break;
		case EXIT:
			studentDB.Save();
			return 0;
		default:
			cout << "잘못된 입력입니다. 다시 입력하세요" << endl;
		}

	}
}