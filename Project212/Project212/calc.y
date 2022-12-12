%{
/*C declarations and #define statements go here*/
	#include <stdio.h>
	#include <math.h>
	#include <ctype.h>
	#define YYSTYPE double
	int yylex(void); 
	void yyerror(constchar *); 
%}
/*bison declarations go here*/
%token NUMBER	  /* define token type NUMBER */
%left '+' '-'     /* + and -are left associative */
%left '*' '/'     /* * and / are left associative */
%% /* grammar rules go here*/
input   : /* empty production to allow an empty input */
		| input line 
		;
line    : expr '\n'   { printf("Result is %f\n", $1); }
expr    : expr '+' term   { $$ = $1 + $3; }
		| expr '-' term   { $$ = $1 - $3; }
		| term            { $$ = $1; }
		;
term    : term '*' factor { $$ = $1 * $3; }
		| term '/' factor { $$ = $1 / $3; }
		| factor          { $$ = $1; }
		;
factor  : '(' expr ')'    { $$ = $2; }
		| NUMBER          { $$ = $1; }
		| '-' NUMBER      { $$ = -$2; }
		;
%%
/* additional C code goes here*/
void yyerror(constchar *errmsg) { 
	printf("%s\n", errmsg);
}
/* main */
int main() {
	printf("type an expression:\n");
	yyparse(); 
}