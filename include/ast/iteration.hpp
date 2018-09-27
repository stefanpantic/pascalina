#pragma once


#include <memory> // unique_ptr
#include "expression.hpp"
#include "statement.hpp"


namespace pascalina
{

	/*
	* @brief AST node for iteration statement.
	*/
	class iteration : public statement
	{
		public:
			explicit iteration(expression *condition, statement *body)
				:	m_condition(std::move(condition)),
					m_body(std::move(body))
			{ std::clog << "[[32mconstructor[0m]" << __PRETTY_FUNCTION__ << std::endl; }

			// Getters
			inline const expression *condition() const { return m_condition.get(); }
			inline const statement *body() const { return m_body.get(); }

			// Accept visitor member function
			llvm::Value *accept(util::visitor &v) const override
			{ return v.visit(*this); }
		private:
			std::unique_ptr<expression> m_condition;
			std::unique_ptr<statement> m_body;
	}; // class pascalina::iteration

} // namespace pascalina
