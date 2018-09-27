#pragma once


#include <algorithm> // transform
#include <vector> // vector
#include <memory> // unique_ptr
#include "statement.hpp"
#include "expression.hpp"


namespace pascalina
{

	/*
	* @brief AST node for writeln statement
	*/
	class writeln : public statement
	{
		public:
			explicit writeln(expression *e)
				:	m_expr(std::move(e))
			{
				std::clog << "[[32mconstructor[0m]" << __PRETTY_FUNCTION__ << std::endl;
			}

			// Getter
			inline const expression *expr() const
			{ return m_expr.get(); }

			// Accept visitor member function
			llvm::Value *accept(util::visitor &v) const override
			{ return v.visit(*this); }
		private:
			std::unique_ptr<expression> m_expr;
	}; // class pascalina::writeln

} // namespace pascalina
