%option noyywrap noinput nounput

%{

#include <iostream> // cerr, endl
#include <string_view> // string_view
#include <vector> // vector
#include "ast.hpp"
#include "types.hpp"
#include "parser.hpp" // generated by yacc


/*
* @brief Extern lexical parsing function.
*/
extern int yylex();

/*
* @brief Extern error handling function.
*/
extern void yyerror(std::string_view msg);

%}


%%

"array"				{ return ARRAY; }
"begin" 			{ return BEGIN_; }
"do"				{ return DO; }
"else"				{ return ELSE; }
"end" 				{ return END_; }
"then"				{ return THEN; }
"if"				{ return IF; }
"not"				{ return NOT; }
"of"				{ return OF; }
"var"				{ return VAR; }
"writeln"			{ return WRITELN; }
"program"			{ return PROGRAM; }
"procedure"			{ return PROCEDURE; }
"function"			{ return FUNCTION; }
"Integer"			{ return INTEGER; }
"Real"				{ return REAL; }
"while" 			{ return WHILE; }
":="				{ return ASSIGN; }
"=="				{ return EQ; }
"!="				{ return NE; }
"<="				{ return LE; }
">="				{ return GE; }
".."				{ return ELIPSIS; }
[a-z][A-Za-z0-9_]*	{
						yylval.identifier = new std::string(yytext);
						return ID;
					}
[0-9]+([.][0-9]+)?	{
						yylval.literal = std::atof(yytext);
						return NUM;
					}
[;:+*<>=/\[\](),.-]	{ return *yytext; }
[\t\n ]				{ /* ignore */ }
.					{ yyerror("Lexical error, invalid token: " + std::string(yytext)); }

%%
