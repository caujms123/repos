#ifndef _Student_H_
#define _Student_H_
using namespace std;
#include<vector>
#include<utility>
enum { INSERT = 1, SEARCH, SORT, EXIT };
namespace search {
	enum { NAME = 1, ID, ADYEAR, DEPT, LIST, MAINMENU };
}
namespace sorting {
	enum { NAME = 1, ID, DEPT, MAINMENU };
}
void ShowMenu(void);
void trim(string &s);
class Student {
private:
	string name; //최대 15자 영어 && not null
	string student_id; // 입학 년도(4자리),학과코드(3자리),대표 번호 3자리&& not null && 겹치는 번호 검색 후 에러표시 떠야함
	string email_address; // 15자리 영어
	string tel;// 최대 12자리
	string admission_year;
	string department;
public:
	Student(string name, string id, string dept, string email, string tel);
	string GetName(void) const;
	string GetID(void) const;
	string GetEmail(void) const;
	string GetTel(void) const;
	string GetAdyear(void) const;
	string GetDept(void) const;
	string GetAll(void) const;
	string GetAllForFile(void) const;
};
class StudentDB {
private:
	int sorting_option;
	string file;
	vector<Student> student_db;
	vector<pair<string, string>> dept;
public:
	StudentDB(string file, string file2);
	void Insert(void);
	void Search(void);
	void Sort(void);
	void Save(void);
	int NumOfStudents(void);
private:
	void DeptMapping(string file2);
	void SearchMenu(void);
	void SortMenu(void);
	void AddStudent(string line);
	void SearchByName(void);
	void SearchByID(void);
	void SearchByAdyear(void);
	void SearchByDept(void);
	void ListAll(void);
	static bool SortByName(Student, Student);
	static bool SortByID(Student, Student);
	static bool SortByDept(Student, Student);
	bool IDCheck(string id);
};
#endif