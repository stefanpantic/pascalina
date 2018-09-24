#include <iostream>
#include <unordered_map>
#include "ast.hpp"
#include "types.hpp"
#include "parser.hpp"

// Global symbol table with identifiers and types.
extern std::unordered_map<std::string, std::unordered_map<std::string, std::unique_ptr<pascalina::types::base>>> symtable;
// Program tree
extern std::unique_ptr<pascalina::program> root;

int
main(int argc, const char **)
{
	yydebug = (argc == 2);
	yyparse();

	// Print scope variables
	for(auto &&e1 : symtable)
	{
		std::cout << "Context: " << e1.first << std::endl;
		for(auto &&e2 : e1.second) {
			std::cout << '\t' << e2.first << std::endl;
		}
	}

	return 0;
}
