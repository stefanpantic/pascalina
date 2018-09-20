#pragma once


#include <memory> // unique_ptr
#include "expression.hpp"
#include "statement.hpp"


namespace kk
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
			{ std::clog << "[constructor]" << __PRETTY_FUNCTION__ << std::endl; }

			// Getters
			inline const expression *condition() const { return m_condition.get(); }
			inline const statement *body() const { return m_body.get(); }

			// Accept visitor member function
			void accept(util::visitor &v) override
			{ v.visit(*this); }
		private:
			std::unique_ptr<expression> m_condition;
			std::unique_ptr<statement> m_body;
	}; // class kk::iteration

} // namespace kk