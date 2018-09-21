#pragma once


#include <iostream> // clog, endl
#include "base.hpp"


namespace pascalina::types
{

	/*
	* @brief AST node for none type.
	*/
	class none : public base
	{
		public:
			none()
				:	base(typetag::none)
			{ std::clog << "[constructor]" << __PRETTY_FUNCTION__ << std::endl; }

			// Overrided clone member function
			base *clone() const override
			{
				return new none;
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
	}; // class pascalina::types::none

} // namespace pascalina::types
