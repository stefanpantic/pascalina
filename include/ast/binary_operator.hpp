#pragma once


#include <memory> // unique_ptr
#include "expression.hpp"


namespace pascalina
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
			explicit binary_operator(pascalina::binary op, expression *lhs, expression *rhs)
				:	m_operator(std::move(op)),
					m_lhs(std::move(lhs)),
					m_rhs(std::move(rhs))
			{ std::clog << "[[32mconstructor[0m]" << __PRETTY_FUNCTION__ << std::endl; }

			// Getters
			inline const binary &op() const { return m_operator; }
			inline const expression *lhs() const { return m_lhs.get(); }
			inline const expression *rhs() const { return m_rhs.get(); }

			// Accept visitor member function
			llvm::Value *accept(util::visitor &v) const override
			{ return v.visit(*this); }
		private:
			binary m_operator;
			std::unique_ptr<expression> m_lhs, m_rhs;
	}; // class pascalina::binary_operator

} // namespace pascalina
