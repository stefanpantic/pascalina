#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <set>
#include "ast.hpp"
#include "types.hpp"
#include "visitor.hpp"
#include "parser.hpp"


// Global symbol table with identifiers and types.
extern std::unordered_map<std::string, std::unordered_map<std::string, std::unique_ptr<pascalina::types::base>>> symtable;
// Program tree
extern std::unique_ptr<pascalina::program> root;
// Error logs
extern std::set<std::string> semantic_errors;

/*
* @brief Error handling function.
*/
extern void yyerror(std::string_view msg);


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

	// Raise semantic error
	if(!semantic_errors.empty())	{
		std::for_each(semantic_errors.begin(), semantic_errors.end(), [] (auto &&e) { std::cout << e << std::endl; });
		yyerror("Semantic errors found, compilation failed.");
	}

	pascalina::visitor llv(std::move(symtable));

	return 0;
}
