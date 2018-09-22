#pragma once


#include <iostream> // clog, endl
#include "base.hpp"


namespace pascalina::types
{

	/*
	* @brief AST node for real type.
	*/
	class real : public base
	{
		public:
			real()
				:	base(typetag::real)
			{ std::clog << "[[32mconstructor[0m]" << __PRETTY_FUNCTION__ << std::endl; }

			// Overrided clone member function
			base *clone() const override
			{
				return new real;
			}

			// Virtual comparisson operators
			bool operator==(const base &other) const override
			{
				return tag() == other.tag();
			}

			bool operator!=(const base &other) const override
			{
				return !(*this == other);
			}
	}; // class pascalina::types::real

} // namespace pascalina::types
