/**
 * This the example lexical analyzer code in pages 173 - 177 of the
 * textbook,
 *
 * Sebesta, R. W. (2012). Concepts of Programming Languages. 
 * Pearson, 10th edition.
 *
 */

/* front.c - a lexical analyzer system for simple arithmetic expressions */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
/* Global Variable */
int nextToken;
int charClass;
char lexeme [100];
char nextChar;
int lexLen;
int token;
int nextToken;

FILE *in_fp;
FILE *out_fp;

/* Local Function declarations */
void addChar();
void getChar();
void getNonBlank();
int lex();

/* Character classes */
#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99

/* Token codes */
#define INT_LIT 10
#define IDENT 11
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAREN 25
#define RIGHT_PAREN 26

#define FOR_CODE 30
#define IF_CODE 31
#define ELSE_CODE 32
#define WHILE_CODE 33
#define DO_CODE 34
#define INT_CODE 35
#define FLOAT_CODE 36
#define SWITCH_CODE 37
#define LBRACE 38
#define RBRACE 39
#define SEMICOLON 40
#define LESS_THAN 41 // <
#define GREATER_THAN 41 // >
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


/******************************************/
/* main driver                            */
/******************************************/
int main() 
{
    /* Open the input data file and process its contents */
    if ((in_fp = fopen("code.in", "r")) == NULL) {
        printf("ERROR - cannot open code.in \n");
    } else {
        getChar();
        do {
            lex();
        } while (nextToken != EOF);
    }

    return 0;
}

/******************************************
 * lookup - a function to lookup operators 
 * and parentheses and return the token 
 ******************************************/
int lookup(char ch) {
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
			nextToken = ASSIGN_OP;
			break;
		case '{':
			addChar();
			nextToken = LBRACE;
			break;
		case '}':
			addChar();
			nextToken = RBRACE;
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
void addChar() {
    if (lexLen <= 98) {  // max length of Lexime is 99
        lexeme[lexLen++] = nextChar;
        lexeme[lexLen] = 0; // '\0'
    } else {
        printf("Error - lexeme is too long \n");
    }
}

/*****************************************************/
/* getChar - a function to get the next character 
          of input and determine its character class */
/*****************************************************/
void getChar() {
    if ((nextChar = getc(in_fp)) != EOF) {
        if (isalpha(nextChar))
            charClass = LETTER;
        else if (isdigit(nextChar))
            charClass = DIGIT;
        else 
			charClass = UNKNOWN;
    } else {
        charClass = EOF;
    }
}

/*****************************************************/
/* getNonBlank - a function to call getChar until it 
           returns a non-whitespace character        */
/*****************************************************/
void getNonBlank() {
    while (isspace(nextChar)) 
		getChar();
}

/*****************************************************/
/* lex - a simple lexical analyzer for arithmetic 
         expressions                                 */
/*****************************************************/
int lex() {
    lexLen = 0;
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
			if (strcmp(lexeme, "for") == 0) {
				nextToken = FOR_CODE;
			}
			else if (strcmp(lexeme, "if") == 0) {
				nextToken = IF_CODE;
			}
			else if (strcmp(lexeme, "else") == 0) {
				nextToken = ELSE_CODE;
			}
			else if (strcmp(lexeme, "while") == 0) {
				nextToken = WHILE_CODE;
			}
			else if (strcmp(lexeme, "do") == 0) {
				nextToken = DO_CODE;
			}
			else if (strcmp(lexeme, "int") == 0) {
				nextToken = INT_CODE;
			}
			else if (strcmp(lexeme, "float") == 0) {
				nextToken = FLOAT_CODE;
			}
			else if (strcmp(lexeme, "switch") == 0) {
				nextToken = SWITCH_CODE;
			}
            break;

        /* Parse integer literals */
        case DIGIT:
            addChar();
            getChar();
            while (charClass == DIGIT) {
                addChar();
                getChar();
            }
            nextToken = INT_LIT;
            break;

        /* Parentheses and operators */
        case UNKNOWN:
            lookup(nextChar);
            getChar();
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
	sprintf(string_fputs, "Next token is: %d, Next lexeme is %s\n", nextToken, lexeme);
    printf("%s",string_fputs);
	out_fp = fopen("code.out", "a");
	fputs(string_fputs, out_fp);
    return nextToken;
} /* End of function lex */
