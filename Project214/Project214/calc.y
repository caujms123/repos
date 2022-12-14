/* Infix notation calculator. */
%{
   #define YYSTYPE double
   #include <ctype.h>
   #include <math.h>
   #include <stdio.h>
   int yylex (void);
   void yyerror (char const *);
%}
/* Bison declarations. */
%token NUM
%left '-' '+'
%left '*' '/' '%'
%left NEG      /* negation--unary minus */
%right '^'      /* exponentiation */
%% /* The grammar follows. */
input: /* empty */
   | input line
   ;
line: '\n'
   | exp '\n' { printf ("\t%.10g\n", $1); }
;
exp: NUM { $$ = $1; }
   | exp '+' exp { $$ = $1 + $3; }
   | exp '-' exp { $$ = $1 - $3; }
   | exp '*' exp { $$ = $1 * $3; }
   | exp '/' exp { $$ = $1 / $3; }
   | exp '%' exp { $$ = fmod($1 , $3); }
   | '-' exp %prec NEG { $$ = -$2; }
   | exp '^' exp { $$ = pow ($1, $3); }
   | '(' exp ')' { $$ = $2; }
   ;
%%void yyerror(char const *s)
{
   fprintf(stderr, "%s\n", s);
}
int main(void)
{
   return yyparse();
}
int yylex(void)
{
   int c;
   /* Skip white space. */
   while ((c = getchar()) == ' ' || c == '\t');
   /* Process numbers. */
   if (c == '.' || isdigit(c))
   {
      ungetc(c, stdin);
      scanf("%lf", &yylval);
      return NUM;
   }
   /* Return end-of-input. */
   if (c == EOF)
      return 0;
   /* Return a single char. */
   return c;
}