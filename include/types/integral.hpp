#pragma once


#include <iostream> // clog, endl
#include "base.hpp"


namespace pascalina::types
{

	/*
	* @brief AST node for integral type.
	*/
	class integral : public base
	{
		public:
			integral()
				:	base(typetag::integral)
			{ std::clog << "[[32mconstructor[0m]" << __PRETTY_FUNCTION__ << std::endl; }

			// Overrided clone member function
			base *clone() const override
			{
				return new integral;
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
	}; // class pascalina::types::integral

} // namespace pascalina::types
