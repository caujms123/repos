#include<iostream>
#include<windows.h>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include<cctype>
#include"Student.h"
using namespace std;
void ShowMenu(void) {
	cout << "--MainMenu--" << endl;
	cout << "1. Insertion" << endl;
	cout << "2. Search" << endl;
	cout << "3. Sorting Option" << endl;
	cout << "4. Exit" << endl;
}
void trim(string &s) {
	s.erase(s.begin(), find_if(s.begin(), s.end(), [](int ch) {
		return !isspace(ch);
	}));
	s.erase(find_if(s.rbegin(), s.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), s.end());
}
Student::Student(string name, string id, string dept,string email, string tel)
	:name(name), student_id(id), department(dept),email_address(email), tel(tel) {
	admission_year = student_id.substr(0, 4);
}
string Student::GetName(void) const {
	return name;
}
string Student::GetID(void) const {
	return student_id;
}
string Student::GetEmail(void) const {
	return email_address;
}
string Student::GetTel(void) const {
	return tel;
}
string Student::GetAdyear(void) const {
	return admission_year;
}
string Student::GetDept(void) const {
	return department;
}
string Student::GetAll(void) const {
	string name, dept, email, blank="                           ";
	name = this->name + blank.substr(0, 15 - this->name.length());
	dept = department + blank.substr(0, 20 - department.length());
	email = email_address + blank.substr(0, 15 - email_address.length());
	//cout << name + " " + student_id + " " + dept + " " + email + " " + tel;
	return name + " " + student_id + "   " + dept+ "   " + email + "   " + tel;
}
string Student::GetAllForFile(void) const {
	return name + "//" + student_id + "//" + department + "//" + email_address + "//" + tel;
};

void StudentDB::SearchMenu(void) {
	cout << "1.Search by name" << endl;
	cout << "2.Search by Student ID (10 numbers)" << endl;
	cout << "3.Search by asmission year (4 numbers)" << endl;
	cout << "4.Search by department name" << endl;
	cout << "5.List All" << endl;
	cout << "6.MainMenu" << endl;
}
void StudentDB::SortMenu(void) {
	cout << "1.Sort by Name" << endl;
	cout << "2.Sort by Student ID" << endl;
	cout << "3.Sort by Department name" << endl;
	cout << "4.MainMenu" << endl;
}

void StudentDB::Insert(void) {
	string name, id, email, tel;
	cout << "(최대 15자 입력) Name : ";
	while (1) {
		getline(cin,name,'\n');
		trim(name);
		if (name.length() > 15) {
			cout << "최대 15자 입니다. 다시입력하세요" << endl << "Name :";
			continue;
		}
		else if (name.empty()) {
			cout << "이름은 입력되어야합니다. 이름을 입력하세요" << endl << "Name :";
			continue;
		}
		if (name.find('/')!=-1) {
			cout << "/ 기호는 사용할 수 없습니다. 다시입력하세요" << endl << "Name :";
			continue;
		}
		//cout << name;
		break;
	}
	cout << "------------------------------------------" << endl;
	for (int i = 0; i < dept.size(); i++)  cout << dept[i].first << " " << dept[i].second << endl;
	cout << "------------------------------------------" << endl;
	cout << "(10자리 코드)Student ID : ";
	while (1) {
		aaa:
		cin >> id;
		while (getchar() != '\n');
		if (id.empty()) {
			cout << "ID는 입력되어야합니다. ID를 입력하세요" << endl << "Name :";
			continue;
		}
		for (int i = 0; i < id.length(); i++)
		{
			if (!isdigit(id[i])) {
				cout << "숫자가 아닌 값은 입력할 수 없습니다.다시 입력하세요" << endl << "ID :";
				goto aaa;
			}
		}
		if (id.length() != 10) { // IDCheck 함수 만들기
			cout << "id는 10자리입니다. 다시입력하세요" << endl << "ID :";
			continue;
		}
		if (IDCheck(id)) {
			continue;
		}
		for (int i = 0; i < NumOfStudents(); i++) {
			if (id == student_db[i].GetID()) {
				cout << "Error : Alreadyinserted, 다시입력하세요" << endl << "Id :";
				goto aaa;
			}
		}
		break;
	}
	cout << "(최대 15자 입력) Email address : ";
	while (1) {
		cin >> email;
		while (getchar() != '\n');
		if (email.length() > 15) {
			cout << "15자를 넘었습니다. 다시입력하세요" << endl << " Email address :";
			continue;
		}
		else if (email.find('/') != -1) {
			cout << "/ 기호는 사용할 수 없습니다. 다시입력하세요" << endl << "Email address :";
			continue;
		}
		break;
	}
	cout << "(최대 12자 입력) Tel : ";
	while (1) {
		cin >> tel;
		while (getchar() != '\n');
		if (tel.length() > 12) {
			cout << "12자를 넘었습니다. 다시입력하세요" << endl << "Tel :";
			continue;
		}
		else if (tel.find('/') != -1) {
			cout << "/ 기호는 사용할 수 없습니다. 다시입력하세요" << endl << "Tel :";
			continue;
		}
		break;
	}
	string dept = id.substr(4, 3);
	for (int i = 0; i < this->dept.size(); i++) {
		if (this->dept[i].first == dept) {
			dept = this->dept[i].second;
		}
	}
	string student = name + "//" + id + "//" + dept + "//" + email + "//" + tel;
	AddStudent(student);
}
StudentDB::StudentDB(string file,string file2) {
	DeptMapping(file2);
	this->file = file;
	string line;
	ifstream myfile(file);
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			AddStudent(line);
		}
	}
	myfile.close();
	// 파일이 없으면 일단 패스. 종료할 때 파일 생성되는걸로.
}
void StudentDB::Search(void) {
	int choice;
	SearchMenu();
	bbb:
	cout << "선택: ";
	cin >> choice;
	while (getchar() != '\n');
	cin.clear();
	cout << endl;
	//cout << choice;
	switch (choice) {
	case search::NAME:
		system("cls");
		SearchByName();
		break;
	case search::ID:
		system("cls");
		SearchByID();
		break;
	case search::ADYEAR:
		system("cls");
		SearchByAdyear();
		break;
	case search::DEPT:
		system("cls");
		SearchByDept();
		break;
	case search::LIST:
		system("cls");
		ListAll();
		break;
	case search::MAINMENU:
		system("cls");
		return;
	default:
		cout << "잘못된 입력입니다. 다시 입력하세요" << endl;
		goto bbb;
	}
}
void StudentDB::Sort(void) {
	int choice;
	SortMenu();
	ccc:
	cout << "선택: ";
	cin >> choice;
	while (getchar() != '\n');
	cin.clear();
	cout << endl;

	switch (choice) {
	case sorting::NAME:
		system("cls");
		sort(student_db.begin(), student_db.end(), SortByName);
		break;
	case sorting::ID:
		system("cls");
		sort(student_db.begin(), student_db.end(), SortByID);
		break;
	case sorting::DEPT:
		system("cls");
		sort(student_db.begin(), student_db.end(), SortByDept);
		break;
	case sorting::MAINMENU:
		system("cls");
		return;
	default:
		cout << "잘못된 입력입니다. 다시 입력하세요" << endl;
		goto ccc;
	}
}
void StudentDB::AddStudent(string line) { //생성할 때 이용 
	//cout << line << endl;
	int a = line.find("//");
	string name = line.substr(0, a);
	string id = line.substr(a+2, 10); a = line.find("//", a + 2);
	string dept = line.substr(a + 2, line.find("//", a + 3) - 2 - a); a = line.find("//", a + 2);
	string email = line.substr(a + 2, line.find("//", a + 3) - 2- a ); a = line.find("//", a + 2);
	string tel = line.substr(a + 2, 12);
	//cout << name + " " + id + " " + dept + " " + email + " " + tel << endl;
	student_db.push_back(*(new Student(name, id, dept, email, tel)));
}
bool StudentDB::SortByName(Student student1, Student student2) {
	if (student1.GetName() > student2.GetName())
		return true;
	return false;
}
bool StudentDB::SortByID(Student student1, Student student2) {
	if (student1.GetID() > student2.GetID())
		return true;
	return false;
}
bool StudentDB::SortByDept(Student student1, Student student2) {
	if (student1.GetDept() > student2.GetDept())
		return true;
	return false;
}
int StudentDB::NumOfStudents(void) {
	return student_db.size();
};
void StudentDB::SearchByName(void) {
	string name;
	cout << "Name : ";
	getline(cin, name, '\n');
	cout << endl;
	cout << "Name         StudentID  Dept     Email		Tel" << endl;
	for (int i = 0; i < NumOfStudents(); i++) {
		//cout << i << endl;
		if (student_db[i].GetName() == name) {
			cout << student_db[i].GetAll() << endl;
		}
	}
	cout << endl <<"Enter 입력 시 MainMenu로 돌아갑니다.";
	while (getchar() != '\n');
}
void StudentDB::SearchByID(void) {
	string id;
	cout << "Student ID : ";
	cin >> id;
	while (getchar() != '\n');
	cout << endl;
	cout << "Name         StudentID  Dept     Email		Tel" << endl;
	for (int i = 0; i < NumOfStudents(); i++) {
		if (student_db[i].GetID() == id) {
			cout << student_db[i].GetAll() << endl;
		}
	}
	cout << endl <<"Enter 입력 시 MainMenu로 돌아갑니다.";
	while (getchar() != '\n');
}
void StudentDB::SearchByAdyear(void) {
	string adyear;
	cout << "Admission year : ";
	cin >> adyear;
	while (getchar() != '\n');
	cout << endl;
	cout << endl;
	cout << "Name         StudentID  Dept     Email		Tel" << endl;
	for (int i = 0; i < NumOfStudents(); i++) {
		if (student_db[i].GetAdyear() == adyear) {
			cout << student_db[i].GetAll() << endl;
		}
	}
	cout << endl <<"Enter 입력 시 MainMenu로 돌아갑니다.";
	while (getchar() != '\n');
}
void StudentDB::SearchByDept(void) {
	string dept;
	cout << "Dpartment name : ";
	cin >> dept;
	while (getchar() != '\n');
	cout << endl;
	cout << endl;
	cout << "Name         StudentID  Dept     Email		Tel" << endl;
	for (int i = 0; i < NumOfStudents(); i++) {
		if (student_db[i].GetDept() == dept) {
			cout << student_db[i].GetAll() << endl;
		}
	}
	cout << endl <<"Enter 입력 시 MainMenu로 돌아갑니다.";
	while (getchar() != '\n');
}
void StudentDB::ListAll(void) {
	cout << "Name            StudentID    Dept                   Email             Tel" << endl;
	for (int i = 0; i < NumOfStudents(); i++) {
		cout << student_db[i].GetAll() << endl;
	}
	cout << endl <<"Enter 입력 시 MainMenu로 돌아갑니다.";
	while (getchar() != '\n');
}
void StudentDB::Save(void) {
	ofstream myfile(file);
	for (int i = 0; i < NumOfStudents(); i++) {
		myfile<<student_db[i].GetAllForFile()<<endl;
	}
	myfile.close();
}
void StudentDB::DeptMapping(string file2) {
	string line;
	ifstream myfile(file2);
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			dept.push_back(make_pair(line.substr(0, 3), line.substr(4, -1)));
		}
	}
	myfile.close();
}
bool StudentDB::IDCheck(string id) {
	for (int i = 0; i < dept.size(); i++) {
		if (id.substr(4, 3) == dept[i].first) {
			return false;
		}
	}
	cout << "존재하지 않는 학과입니다.다시 입력하세요" << endl << "Id :";
	return true;
}
/*
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string str, char delimiter);

int main(){
	string test = "min sung kang";
	vector<string> result = split(test, ' ');
	for (int i=0;i<result.length();i++){
		cout << result[i] << " ";
	}
}

vector<string> split(string input, char delimiter) {
	vector<string> answer;
	stringstream ss(input);
	string temp;

	while (getline(ss, temp, delimiter)) {
		answer.push_back(temp);
	}

	return answer;
}
*/