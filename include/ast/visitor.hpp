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
				virtual void visit(const assignment &) const = 0;
				virtual void visit(const binary_operator &) const = 0;
				virtual void visit(const compound &) const = 0;
				virtual void visit(const function_call &) const = 0;
				virtual void visit(const function &) const = 0;
				virtual void visit(const function_prototype &) const = 0;
				virtual void visit(const identifier &) const = 0;
				virtual void visit(const iteration &) const = 0;
				virtual void visit(const literal &) const = 0;
				virtual void visit(const procedure_call &) const = 0;
				virtual void visit(const program &) const = 0;
				virtual void visit(const selection &) const = 0;
				virtual void visit(const unary_operator &) const = 0;
				virtual void visit(const var &) const = 0;
		}; // class pascalina::util::visitor

	} // namespace pascalina::util

} // namespace pascalina



