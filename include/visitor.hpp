#pragma once


namespace pascalina
{

	/* Forward declarations */
	class assignment;
	class binary_operator;
	class compound;
	class function;
	class function_call;
	class function_prototype;
	class identifier;
	class iteration;
	class literal;
	class program; /* TODO: Implement program node */
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
				virtual void visit(assignment &) = 0;
				virtual void visit(binary_operator &) = 0;
				virtual void visit(compound &) = 0;
				virtual void visit(function &) = 0;
				virtual void visit(function_call &) = 0;
				virtual void visit(function_prototype &) = 0;
				virtual void visit(identifier &) = 0;
				virtual void visit(iteration &) = 0;
				virtual void visit(literal &) = 0;
				virtual void visit(program &) = 0;
				virtual void visit(selection &) = 0;
				virtual void visit(unary_operator &) = 0;
				virtual void visit(var &) = 0;
		}; // class pascalina::util::visitor

	} // namespace pascalina::util

} // namespace pascalina



