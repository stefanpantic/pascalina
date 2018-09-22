#pragma once


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
	class procedure_call;
	class program;
	class selection;
	class unary_operator;
	class var;

	namespace util
	{

		/*
		* @brief Visitor base class for AST nodes.
		*/
		class visitor
		{
			public:
				virtual void visit(const assignment &) = 0;
				virtual void visit(const binary_operator &) = 0;
				virtual void visit(const compound &) = 0;
				virtual void visit(const function_call &) = 0;
				virtual void visit(const function &) = 0;
				virtual void visit(const function_prototype &) = 0;
				virtual void visit(const identifier &) = 0;
				virtual void visit(const iteration &) = 0;
				virtual void visit(const literal &) = 0;
				virtual void visit(const procedure_call &) = 0;
				virtual void visit(const program &) = 0;
				virtual void visit(const selection &) = 0;
				virtual void visit(const unary_operator &) = 0;
				virtual void visit(const var &) = 0;
		}; // class pascalina::util::visitor

	} // namespace pascalina::util

} // namespace pascalina



