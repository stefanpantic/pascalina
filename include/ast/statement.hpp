#pragma once


#include <iostream>
#include "base.hpp"
#include "visitor.hpp"


namespace pascalina
{

	/*
	* @brief Statement node base class.
	*/
	class statement : public base<util::visitor>
	{
		public:
			// Virtual destructor
			virtual ~statement() {}

			// Accept visitor member function
			virtual llvm::Value *accept(util::visitor &v) const = 0;
	}; // class pascalina::expression


} // namespace pascalina


