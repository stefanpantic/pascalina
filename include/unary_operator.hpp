#pragma once


#include <memory> // unique_ptr
#include "expression.hpp"


namespace kk
{

	/*
	* @brief Enumerated unary operators.
	*/
	enum class unary
	{
		minus,
		logical_not,
	};


	/*
	* @brief AST node for unary operators
	*/
	class unary_operator : public expression
	{
		public:
			explicit unary_operator(kk::unary op, expression *rhs)
				:	m_operator(std::move(op)),
					m_rhs(std::move(rhs))
			{ std::clog << "[constructor]" << __PRETTY_FUNCTION__ << std::endl; }

			// Getters
			inline const unary &op() const { return m_operator; }
			inline const expression *rhs() const { return m_rhs.get(); }

			// Accept visitor member function
			void accept(util::visitor &v) override
			{ v.visit(*this); }
		private:
			unary m_operator;
			std::unique_ptr<expression> m_rhs;
	}; // class kk::unary_operator

} // namespace kk
