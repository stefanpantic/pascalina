#pragma once


#include <memory> // unique_ptr
#include "expression.hpp"


namespace kk
{

	/*
	* @brief Enumerated binary operators.
	*/
	enum class binary
	{
		divides,
		equal_to,
		greater,
		greater_equal,
		less,
		less_equal,
		minus,
		multiplies,
		not_equal_to,
		plus,
	};


	/*
	* @brief AST node for binary operators
	*/
	class binary_operator : public expression
	{
		public:
			explicit binary_operator(kk::binary op, expression *lhs, expression *rhs)
				:	m_operator(std::move(op)),
					m_lhs(std::move(lhs)),
					m_rhs(std::move(rhs))
			{ std::clog << "[constructor]" << __PRETTY_FUNCTION__ << std::endl; }

			// Getters
			inline const binary &op() const { return m_operator; }
			inline const expression *lhs() const { return m_lhs.get(); }
			inline const expression *rhs() const { return m_rhs.get(); }

			// Accept visitor member function
			void accept(util::visitor &v) override
			{ v.visit(*this); }
		private:
			binary m_operator;
			std::unique_ptr<expression> m_lhs, m_rhs;
	}; // class kk::binary_operator

} // namespace kk
