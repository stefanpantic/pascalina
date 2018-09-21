#include <iostream>
#include "ast.hpp"
#include "types.hpp"
#include "parser.hpp"

int
main(void)
{
	yydebug = 1;
	yyparse();
	return 0;
}
