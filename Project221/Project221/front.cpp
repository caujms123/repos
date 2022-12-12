/**
 * This the example lexical analyzer code in pages 173 - 177 of the
 * textbook,
 *
 * Sebesta, R. W. (2012). Concepts of Programming Languages.
 * Pearson, 10th edition.
 *
 */

 /* front.c - a lexical analyzer system for simple arithmetic expressions */
#include <iostream>
#include <string>
#include "front.h"
using namespace std;
/*
Modify the lexical analyzer given in Section 4.2 to recognize the fol￾lowing list of reserved words and return their respective token codes:
for (FOR_CODE, 30), if (IF_CODE, 31), else (ELSE_CODE, 32), while
(WHILE_CODE, 33), do (DO_CODE, 34), int (INT_CODE, 35), float
(FLOAT_CODE, 36), switch (SWITCH_CODE, 37).

int i;
float sum=0;
float total;

for (i=0; i < 10; i=i+1)
	sum = sum + i;
if (sum > 10)
	total = sum + 5;
else
	total = sum * 5;
while (total > 10)
	total = total - 1;
do {
	i = i - 1;
} while (i > 10);

*/

/******************************************
 * lookup - a function to lookup operators
 * and parentheses and return the token
 ******************************************/
int Lexer::lookup(char ch) {
	switch (ch) {
	case '(':
		addChar();
		nextToken = LEFT_PAREN;
		break;
	case ')':
		addChar();
		nextToken = RIGHT_PAREN;
		break;
	case '+':
		addChar();
		nextToken = ADD_OP;
		break;
	case '-':
		addChar();
		nextToken = SUB_OP;
		break;
	case '*':
		addChar();
		nextToken = MULT_OP;
		break;
	case '/':
		addChar();
		nextToken = DIV_OP;
		break;
	case '=':
		addChar();
		nextToken = EQUAL_CODE;
		break;
	case ';':
		addChar();
		nextToken = SEMICOLON;
		break;
	case '<':
		addChar();
		nextToken = LESS_THAN;
		break;
	case '>':
		addChar();
		nextToken = GREATER_THAN;
		break;
	case '\'':
		addChar();
		nextToken = QUOTE_CODE;
		break;
	default:
		addChar();
		nextToken = EOF;
		break;
	}
	return nextToken;
}

/**************************************************/
/* addChar - a function to add nextChar to lexeme */
/**************************************************/
void Lexer::addChar() {
	lexeme += nextChar;
}

/*****************************************************/
/* getChar - a function to get the next character
		  of input and determine its character class */
		  /*****************************************************/
void Lexer::getChar() {
	if ((nextChar = getc(in_fp)) != EOF) {
		if (isalpha(nextChar)) {
			if (islower(nextChar) != 0) {
				nextChar = toupper(nextChar);
			}
			charClass = LETTER;
		}
		else if (isdigit(nextChar))
			charClass = DIGIT;
		else if (nextChar == '.')
			charClass = DOT;
		else if (nextChar == ' ')
			charClass = BLANK;
		else if (nextChar == '(')
			charClass = LEFT_PAREN;
		else if (nextChar == ')')
			charClass = RIGHT_PAREN;
		else if (LESS_THAN == '<')
			charClass = LESS_THAN;
		else if (GREATER_THAN == '>')
			charClass = GREATER_THAN;
		else
			charClass = UNKNOWN;
	}
	else {
		charClass = EOF;
	}
}

/*****************************************************/
/* getNonBlank - a function to call getChar until it
		   returns a non-whitespace character        */
		   /*****************************************************/
void Lexer::getNonBlank() {
	while (isspace(nextChar))
		getChar();
}

/*****************************************************/
/* lex - a simple lexical analyzer for arithmetic
		 expressions                                 */
		 /*****************************************************/
int Lexer::lex() {
	lexeme.clear();
	if (charClass != BLANK && charClass == UNKNOWN) {
		error();
	}
	getNonBlank();
	switch (charClass) {
		/* Parse identifiers */
	case LETTER:
		addChar();
		getChar();
		while (charClass == LETTER || charClass == DIGIT) {
			addChar();
			getChar();
		}
		nextToken = IDENT;
		//****************************************
		if (lexeme == "SETQ") {
			nextToken = SETQ_CODE;
		}
		else if (lexeme == "LIST") {
			nextToken = LIST_CODE;
		}
		else if (lexeme == "CAR") {
			nextToken = CAR_CODE;
		}
		else if (lexeme == "CDR") {
			nextToken = CDR_CODE;
		}
		else if (lexeme == "NTH") {
			nextToken = NTH_CODE;
		}
		else if (lexeme == "CONS") {
			nextToken = CONS_CODE;
		}
		else if (lexeme == "REVERSE") {
			nextToken = REVERSE_CODE;
		}
		else if (lexeme == "APPEND") {
			nextToken = APPEND_CODE;
		}
		else if (lexeme == "LENGTH") {
			nextToken = LENGTH_CODE;
		}
		else if (lexeme == "ASSOC") {
			nextToken = ASSOC_CODE;
		}
		else if (lexeme == "REMOVE") {
			nextToken = REMOVE_CODE;
		}
		else if (lexeme == "SUBST") {
			nextToken = SUBST_CODE;
		}

		else if (lexeme == "ATOM") {
			nextToken = ATOM_CODE;
		}
		else if (lexeme == "NULL") {
			nextToken = NULL_CODE;
		}
		else if (lexeme == "NUMVERP") {
			nextToken = NUMBERP_CODE;
		}
		else if (lexeme == "ZEROP") {
			nextToken = ZEROP_CODE;
		}
		else if (lexeme == "MINUSP") {
			nextToken = MINUSP_CODE;
		}
		else if (lexeme == "EQUAL") {
			nextToken = EQUAL_CODE;
		}
		else if (lexeme == "STRINGP") {
			nextToken = STRINGP_CODE;
		}
		else if (lexeme == "IF") {
			nextToken = IF_CODE;
		}
		else if (lexeme == "COND") {
			nextToken = COND_CODE;
		}
		if (!((charClass == BLANK) || (charClass == RIGHT_PAREN) || (charClass == LEFT_PAREN))) error();
		break;

		/* Parse integer literals */
	case DIGIT: case DOT: {
		addChar();
		getChar();
		bool isdouble = false;
		while (charClass == DIGIT || charClass == DOT) {
			addChar();
			getChar();
			if (charClass == DOT) {
				if (isdouble) error(); // DOT를 들어왔을 때 isdouble이 true 라면, 소수점이 2개 이상 나온 것임. 에러.
				else isdouble = true;
			}
		}
		if (!((charClass == BLANK) || (charClass == RIGHT_PAREN) || (charClass == LEFT_PAREN))) error();
		if (isdouble) {
			nextToken = DOUBLE_LIT;
			break;
		}
		nextToken = INT_LIT;
		break;
	}
				/* Parentheses and operators */
	case LEFT_PAREN: case RIGHT_PAREN:
		lookup(nextChar);
		getChar();
		break;
	case UNKNOWN:
		lookup(nextChar);
		getChar();
		if (!((charClass == BLANK) || (charClass == RIGHT_PAREN) || (charClass == LEFT_PAREN))) error();
		break;
	case LESS_THAN: case GREATER_THAN: // <= >= 인식하기 위해 분류하였음
		lookup(nextChar);
		getChar();
		if (!((charClass == BLANK) || (charClass == RIGHT_PAREN) ||
			(charClass == LEFT_PAREN) || (charClass == EQUAL_CODE) || (charClass == GREATER_THAN))) error();
		break;
		/* EOF */
	case EOF:
		nextToken = EOF;
		lexeme[0] = 'E';
		lexeme[1] = 'O';
		lexeme[2] = 'F';
		lexeme[3] = 0;
		break;
	} /* End of switch */
	char string_fputs[1000];
	cout << "Next token is:<< nextToken <<, Next lexeme is " << lexeme << endl;
	return nextToken;
} /* End of function lex */