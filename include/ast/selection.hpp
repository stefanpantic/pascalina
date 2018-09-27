#pragma once


#include <memory> // unique_ptr
#include "none.hpp"
#include "expression.hpp"
#include "statement.hpp"


namespace pascalina
{

	/*
	* @brief AST node for selection statements.
	*/
	class selection : public statement
	{
		public:
			explicit selection(expression *condition, statement *then, statement *elif = new none)
				:	m_condition(std::move(condition)),
					m_then(std::move(then)),
					m_elif(std::move(elif))
			{ std::clog << "[[32mconstructor[0m]" << __PRETTY_FUNCTION__ << std::endl; }

			// Getters
			inline const expression *condition() const { return m_condition.get(); }
			inline const statement *then() const { return m_then.get(); }
			inline const statement *elif() const { return m_elif.get(); }

			// Accept visitor member function
			llvm::Value *accept(util::visitor &v) const override
			{ return v.visit(*this); }
		private:
			std::unique_ptr<expression> m_condition;
			std::unique_ptr<statement> m_then, m_elif;
	}; // class pascalina::selection

} // namespace pascalina
