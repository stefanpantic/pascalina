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
			explicit literal(float val)
				:	m_val(std::move(val))
			{ std::clog << "[[32mconstructor[0m]" << __PRETTY_FUNCTION__ << std::endl; }

			// Getter
			inline const float &val() const { return m_val; }

			// Accept visitor member function
			void accept(util::visitor &v) const override
			{ v.visit(*this); }
		private:
			float m_val;

	}; // class pascalina::expression

} // namespace pascalina
