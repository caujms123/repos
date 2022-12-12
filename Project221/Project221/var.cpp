#include <iostream>
#include <string>
#include "front.h"
void var::error_check(short valid) { // Ÿ���� ���� ���ų� DOUBLE <-> INT ���̰ų� NUL �� �Ϳ��� error�� �ȳ���.
	if ((this->valid == NUL) || (this->valid == valid) || ((this->valid == DOUBLE) && (valid == INT)) || ((this->valid == INT) && (valid == DOUBLE))) {}
	else error();
}
void var::int_double() { // INT�� ������ DOUBLE�� ���� �ְų� ����� �� ����ȯ
	if (valid == INT) {
		double_number = int_number;
		int_number = 0;
		valid = DOUBLE;
	}
}

var& var::operator=(const var& num) { // var ���� ����ȯ
	short num_type = num.valid;
	error_check(num_type);
	switch (num_type) {
	case LIST:
		list = num.list;
		valid = LIST;
		break;
	case DOUBLE:
		int_double();
		double_number = num.double_number;
		valid = DOUBLE;
		break;
	case INT:
		if (valid == DOUBLE) {
			int_number = double_number;
			double_number = 0;
			valid == INT;
		}
		int_number = num.int_number;
		valid = INT;
		break;
	case STRING:
		str = num.str;
		valid = STRING;
		break;
	case BOOL:
		str = num.str;
		valid = BOOL;
		break;
	default: error();
	}
	return *this;
}

var& var::operator+(const var& num) { // var Ÿ�� ��Ģ���� �����ε�
	short num_type = num.valid;
	error_check(num_type);
	switch (num_type) {
	case DOUBLE:
		int_double();
		double_number += num.double_number;
		valid = DOUBLE;
		break;
	case INT:
		if (valid == DOUBLE)
			double_number += num.int_number;
		else int_number += num.int_number;
		break;
	default: error();
	}
	return *this;
}
var& var::operator-(const var& num) {
	short num_type = num.valid;
	error_check(num_type);
	switch (num_type) {
	case DOUBLE:
		int_double();
		double_number -= num.double_number;
		valid = DOUBLE;
		break;
	case INT:
		if (valid == DOUBLE)
			double_number -= num.int_number;
		else int_number -= num.int_number;
		break;
	default: error();
	}
	return *this;
}
var& var::operator*(const var& num) {
	short num_type = num.valid;
	error_check(num_type);
	switch (num_type) {
	case DOUBLE:
		int_double();
		double_number *= num.double_number;
		valid = DOUBLE;
		break;
	case INT:
		if (valid == DOUBLE)
			double_number *= num.int_number;
		else int_number *= num.int_number;
		break;
	default: error();
	}
	return *this;
}
var& var::operator/(const var& num) {
	short num_type = num.valid;
	error_check(num_type);
	switch (num_type) {
	case DOUBLE:
		int_double();
		double_number /= num.double_number;
		valid = DOUBLE;
		break;
	case INT:
		if (valid == DOUBLE)
			double_number /= num.int_number;
		else int_number /= num.int_number;
		break;
	default: error();
	}
	return *this;
}
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
var& var::operator=(double num) {
	error_check(DOUBLE);
	int_double();
	double_number = num;
	valid = DOUBLE;
	return *this;
}
var& var::operator=(int num) {
	error_check(INT);
	if (valid == DOUBLE) {
		int_number = double_number;
		double_number = 0;
		valid == INT;
	}
	int_number = num;
	valid = INT;
	return *this;
}
var& var::operator=(string in) {
	error_check(STRING);
	str = in;
	valid = STRING;
	return *this;
}

var& var::operator+(double num) {
	error_check(DOUBLE);
	int_double();
	double_number += num;
	valid = DOUBLE;
	return *this;
}
var& var::operator-(double num) {
	error_check(DOUBLE);
	int_double();
	double_number -= num;
	valid = DOUBLE;
	return *this;
}
var& var::operator*(double num) {
	error_check(DOUBLE);
	int_double();
	double_number *= num;
	valid = DOUBLE;
	return *this;
}
var& var::operator/(double num) {
	error_check(DOUBLE);
	int_double();
	double_number /= num;
	valid = DOUBLE;
	return *this;
}

var& var::operator+(int num) {
	error_check(INT);
	if (valid == DOUBLE)
		double_number += num;
	else int_number += num;
	return *this;
}
var& var::operator-(int num) {
	error_check(INT);
	if (valid == DOUBLE)
		double_number -= num;
	else int_number -= num;
	return *this;
}
var& var::operator*(int num) {
	error_check(INT);
	if (valid == DOUBLE)
		double_number *= num;
	else int_number *= num;
	return *this;
}
var& var::operator/(int num) {
	error_check(INT);
	if (valid == DOUBLE)
		double_number /= num;
	else int_number /= num;
	return *this;
}
short var::type_check() { // ���� ��� ������ ȣȯ �ȵǹǷ� ������ if(type_check() == 1) �̷������� �����
	return valid;
}
var* var::find(string atom,var * start) {
	var* pt = start;
	for (; pt != nullptr; pt = pt->next) {
		if (!atom.compare(pt->name)) break;
	}
	return pt;
}
void var::push(var * start) {
	var* cur = find(name, start);
	if (cur == nullptr) {
		cur = new var;
		if (start == nullptr)
			start = cur;
		else {
			var* pt = start;
			for (; pt->next == nullptr; pt = pt->next);
			pt->next = cur;
		}
	}
	cur->valid = valid;
	switch (valid) {
	case 0:
		cur->valid = 0;
		break;
	case 1:
		cur->valid = 1;
		cur->list = list;
		break;
	case 2:
		cur->valid = 2;
		cur->double_number = double_number;
		break;
	case 3:
		cur->valid = 3;
		cur->int_number = int_number;
		break;
	case 4:
		cur->valid = 4;
		cur->str = str;
		break;
	case 5:
		cur->valid = 5;
		cur->tf = tf;
		break;
	}
}
string var::liststr(var* list) {
	string result = "(";
	var* pt = list;
	for (; pt == nullptr; pt = pt->next) {
		switch (pt->valid) {
		case 0:
			result += "NIL ";
			break;
		case 1:
			result += liststr(pt->list) + " ";
			break;
		case 2:
			result += to_string(double_number) + " ";
			break;
		case 3:
			result += to_string(int_number) + " ";
			break;
		case 4:
			result += str + " ";
			break;
		case 5:
			if (tf) result += "T ";
			else result += "NIL ";
			break;
		}
	}
	return result + ")";
}
void var::print() { // ��� ������ ���ؼ� ����ϴ� �Լ� �ʿ�
	switch (valid) {
	case LIST: cout << liststr(list) << endl; break;//����Ʈ ����ϴ� �� 
	case DOUBLE: cout << double_number << endl; break;
	case INT: cout << int_number << endl; break;
	case STRING: cout << str << endl; break;
	case BOOL:
		if (tf == true) cout << "T" << endl;
		else  cout << "NIL" << endl;
		break;
	}
}