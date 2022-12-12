#ifndef __front_H
#define __front_H

/* Global Variable */
/* Character classes */
#define LETTER 0
#define DIGIT 1
#define DOT 2
#define BLANK 3
#define LINE_BREAK 3
#define UNKNOWN 99

/* Token codes */
#define DOUBLE_LIT 9
#define INT_LIT 10
#define IDENT 11

#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAREN 25 // (
#define RIGHT_PAREN 26 // )

#define SEMICOLON 39
#define LESS_THAN 40 // <
#define GREATER_THAN 41 // >

#define SETQ_CODE 42
#define LIST_CODE 43
#define CAR_CODE 44
#define CDR_CODE 45
#define NTH_CODE 46
#define CONS_CODE 47
#define REVERSE_CODE 48
#define APPEND_CODE 49
#define LENGTH_CODE 50
#define ASSOC_CODE 51
#define REMOVE_CODE 52
#define SUBST_CODE 53

#define ATOM_CODE 54 
#define NULL_CODE 55
#define NUMBERP_CODE 56
#define ZEROP_CODE 57
#define MINUSP_CODE 58
#define	EQUAL_CODE 59
#define STRINGP_CODE 60
#define IF_CODE 61
#define COND_CODE 62
#define QUOTE_CODE 63
#define MEMBER_CODE 64 // 중간에 뺴먹음
// <=, >= 는?
using namespace std;
/* Local Function declarations */
void error(void);
class var {
public:
	string name;        // 변수명
	short valid = NUL;        // 0= NUL 1 = list, 2 = double, 3 = int, 4 = string, 5.bool
	enum { NUL, LIST, DOUBLE, INT, STRING, BOOL };
	var* list;
	double double_number;
	int int_number;
	string str;
	bool tf;
	var* next;          // 변수 linked list
public:
	void error_check(short valid);
	void int_double();
	var& operator=(const var& num);
	var& operator+(const var& num);
	var& operator-(const var& num);
	var& operator*(const var& num);
	var& operator/(const var& num);
	/*void operator=(var* copy) {
		valid = copy->valid;
		error_check(copy->valid);
		switch (copy->valid) {
		case 1:
			list = copy->list;
			valid = LIST;
			break;
		case 2:
			int_double();
			double_number = copy->double_number;
			valid = DOUBLE;
			break;
		case 3:
			if (valid == DOUBLE) {
				int_number = double_number;
				double_number = 0;
				valid == INT;
			}
			int_number = copy->int_number;
			valid = INT;
			break;
		case 4:
			str = copy->str;
			valid = STRING;
			break;
		case 5:
			tf = copy->tf;
			valid = BOOL;
			break;
		default: error();
	}*/
	var& operator=(double num);
	var& operator=(int num);
	var& operator=(string in);
	var& operator+(double num);
	var& operator-(double num);
	var& operator*(double num);
	var& operator/(double num);
	var& operator+(int num);
	var& operator-(int num);
	var& operator*(int num);
	var& operator/(int num);
	short type_check();
	var* find(string atom,var * start);
	void push(var * start);
	string liststr(var* list);
	void print();
};
class Lexer {
public:
	int nextToken;
	int charClass;
	string lexeme;
	char nextChar;
	int token;

	FILE *in_fp;
public:
	void addChar();
	void getChar();
	void getNonBlank();
	int lex();
	int lookup(char ch);
};

class Parser {
public:
	//var* varlist;
	//var* result;
	var* start;
	Lexer &lexer;
	int nextToken;
public:
	Parser(Lexer&, var*);
	bool isReturnNum(void); //return 값이 숫자인 모든 데이터,함수들 (후보를 갖고 있으면 전부 포함)
	bool isReturnList(void); // return 값이 list인 모든 데이터, 함수들 
	bool isReturnStr(void); // return 값이 str인 모든 데이터, 함수들 
	bool isReturnF(void); //NIL 만 반환 가능 True는 반환하지 못함.
	bool isReturnTF(void); // True 도 반환 가능
	bool isCondition(void);

	var program(void);
	var returnIsNum(void); //return 값이 숫자인 모든 데이터,함수들 (후보를 갖고 있으면 전부 포함)
	var returnIsList(void); // return 값이 list인 모든 데이터, 함수들 
	var returnIsStr(void); // return 값이 str인 모든 데이터, 함수들 
	var returnIsF(void); // 
	var returnIsTF(void);
	/*double prefixcal();
	var* expr(void);
	var* term(void);
	var* factor(void);
	void setq(void);
		var& stmt_list(void);
	*/
	string lex(void);
	string lexeme(void);
	/*
	var* list() {};
	var* car() {};
	var* cdr() {};
	var* nth() {};
	var* cons() {};
	var* reverse() {};
	var* append() {};
	var* length() {};
	var* member() {};
	var* assoc(){};
	var* remove() {};
	var* subst() {};
	var* atom() {};
	var* null() {};
	var* numberp() {};
	var* zerop() {};
	var* minusp() {};
	var* equal() {};
	var* stringp() {};
	var* if_stemt () {};
	var* cond() {};*/
};
#endif