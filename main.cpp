#include <iostream>
#include <unordered_map>
#include "ast.hpp"
#include "types.hpp"
#include "visitors/traverse.hpp"
#include "parser.hpp"

// Global symbol table with identifiers and types.
extern std::unordered_map<std::string, pascalina::types::base*> type_map;
// Program tree
extern std::unique_ptr<pascalina::program> root;

int
main(int argc, const char **)
{
	yydebug = (argc == 2);
	yyparse();

	for(auto &&e : type_map) {
		delete e.second;
	}

	pascalina::util::traverse traverser;
	traverser.visit(*root.get());

	return 0;
}
