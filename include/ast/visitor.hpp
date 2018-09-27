#pragma once


#include <llvm/IR/Value.h>


namespace pascalina
{

	/* Forward declarations */
	class assignment;
	class binary_operator;
	class compound;
	class function_call;
	class function;
	class function_prototype;
	class identifier;
	class iteration;
	class literal;
	class none;
	class procedure_call;
	class program;
	class selection;
	class unary_operator;
	class var;
	class writeln;

	namespace util
	{

		/*
		* @brief Visitor base class for AST nodes.
		*/
		class visitor
		{
			public:
				virtual llvm::Value *visit(const assignment &) = 0;
				virtual llvm::Value *visit(const binary_operator &) = 0;
				virtual llvm::Value *visit(const compound &) = 0;
				virtual llvm::Value *visit(const function_call &) = 0;
				virtual llvm::Value *visit(const function &) = 0;
				virtual llvm::Value *visit(const function_prototype &) = 0;
				virtual llvm::Value *visit(const identifier &) = 0;
				virtual llvm::Value *visit(const iteration &) = 0;
				virtual llvm::Value *visit(const literal &) = 0;
				virtual llvm::Value *visit(const none &) = 0;
				virtual llvm::Value *visit(const procedure_call &) = 0;
				virtual llvm::Value *visit(const program &) = 0;
				virtual llvm::Value *visit(const selection &) = 0;
				virtual llvm::Value *visit(const unary_operator &) = 0;
				virtual llvm::Value *visit(const var &) = 0;
				virtual llvm::Value *visit(const writeln &) = 0;

				// Virtual destructor
				virtual ~visitor() {}
		}; // class pascalina::util::visitor

	} // namespace pascalina::util

} // namespace pascalina



