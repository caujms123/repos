/******************************************/
/* main driver                            */
/******************************************/
#include <iostream>
#include <string>
#include "front.h"

using namespace std;
int main()
{
	var* first = new var();
	Lexer lexer;
	Parser parse(lexer, first);
	/* Open the input data file and process its contents */
	if ((lexer.in_fp = fopen("code.in", "r")) == NULL) {
		printf("ERROR - cannot open code.in \n");
	}
	else {
		lexer.getChar();
		do {
			var result = parse.program();
			result.print(); // _var ���� �Լ� ���� result ����� �� �ְ� ����.
		} while (parse.nextToken != EOF);
	}
	return 0;
}


