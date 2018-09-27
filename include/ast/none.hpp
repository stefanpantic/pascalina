#pragma once


#include "statement.hpp"


namespace pascalina
{

	/*
	* @brief AST node for none.
	*/
	class none : public statement
	{
		public:
			explicit none()
			{ std::clog << "[[32mconstructor[0m]" << __PRETTY_FUNCTION__ << std::endl; }

			// Accept visitor member function
			llvm::Value *accept(util::visitor &v) const override
			{ return v.visit(*this); }
	}; // class pascalina::none

} // namespace pascalina
