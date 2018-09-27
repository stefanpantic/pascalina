#pragma once


#include "expression.hpp"


namespace pascalina
{

	/*
	* @brief AST node for literal expression.
	*/
	class literal : public expression
	{
		public:
			explicit literal(double val)
				:	m_val(std::move(val))
			{ std::clog << "[[32mconstructor[0m]" << __PRETTY_FUNCTION__ << std::endl; }

			// Getter
			inline const double &val() const { return m_val; }

			// Accept visitor member function
			llvm::Value *accept(util::visitor &v) const override
			{ return v.visit(*this); }
		private:
			double m_val;

	}; // class pascalina::expression

} // namespace pascalina
