#pragma once


#include <iostream>
#include "base.hpp"
#include "visitor.hpp"


namespace pascalina
{

	/*
	* @brief Expression node base class.
	*/
	class expression : public base<util::visitor>
	{
		public:
			// Virtual destructor
			virtual ~expression() {}

			// Accept visitor member function
			virtual void accept(util::visitor &v) const = 0;
	}; // class pascalina::expression


} // namespace pascalina


