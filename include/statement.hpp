#pragma once


#include <iostream>
#include "base.hpp"
#include "visitor.hpp"


namespace pascalina
{

	/*
	* @brief Statement node base class.
	*/
	class statement : public pascalina::base<util::visitor>
	{
		public:
			// Virtual destructor
			virtual ~statement() {}

			// Accept visitor member function
			virtual void accept(util::visitor &v) = 0;
	}; // class pascalina::expression


} // namespace pascalina


